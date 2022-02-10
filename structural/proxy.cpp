# include <iostream>
# include <map>
# define NOT_FOUND -1

using namespace std;

class subject {
protected:
    map<string, int> table;
public:

    subject() {};

    virtual int request(string question) {
        auto ans = table.find(question);
        if (ans != table.end()) {

            return ans->second;
        }
        return NOT_FOUND;
    }

    void addTable(pair<string, int> p) {
        this->table.insert(p);
    }
};

class proxy : public subject {
private:
    subject *s;
public:
    proxy(subject *s) : subject(), s(s) {};

    int request(string question) {
        int answer = subject::request(question);
        if (answer == NOT_FOUND) {
            answer = s->request(question);
            if (answer == NOT_FOUND) {
                cout << "not exist, sorry" << endl;
                return answer;
            }
        }
        cout << "the age is: " << answer << endl;
        addTable(pair<string, int>(question, answer));
        return answer;
    }

};

class realSubject : public subject {
public:
    realSubject() : subject() {};

    int request(string question) {
        cout << "pass in proxy" << endl;
        int answer = subject::request(question);
        if (answer == NOT_FOUND) {
            return NOT_FOUND;
        }
        return answer;
    }
};

//int main() {
//    subject *real = new realSubject;
//    real->addTable(pair<string, int>("noam", 26));
//    real->addTable(pair<string, int>("david", 30));
//    real->addTable(pair<string, int>("yossi", 55));
//    subject *proxyUser = new proxy(real);
//    proxyUser->request("noam");
//    proxyUser->request("dsfs");
//    proxyUser->request("noam");
//
//
//}