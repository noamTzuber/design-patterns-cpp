#include <iostream>
#include <map>

using namespace std;

//kind of  workers
class worker {
public:
    worker() {}

    virtual void print() {
        cout << "im worker" << endl;
    }
};

class manager : public worker {
public :
    manager() : worker() {};
    void print() override {
        cout << "im manager" << endl;
    }
};

class simpleWorker : public worker {
public :
    simpleWorker() : worker() {};

    void print()override {
        cout << "im simpleWorker" << endl;
    }
};

class headTeam : public worker {
public :
    headTeam() : worker() {};
    void print()override {
        cout << "im headTeam" << endl;
    }
};

// kind of creators
class creator {
public:
    creator(){};
    virtual worker* create()=0;
};

class managerCreator : public creator {
public:
    managerCreator() : creator(){};
    worker * create() {
        return new manager();
    }
};

class headTeamCreator : public creator {
public:
    headTeamCreator() : creator(){}

    worker * create() {
        return new headTeam();
    }
};

class simpleWorkerCreator : public creator {
public:
    simpleWorkerCreator() : creator(){}

    worker * create() {
        return new simpleWorker();
    }
};

worker* findInMyFactory(string name, map<string, creator*> factory) {
    map<string, creator*>::iterator it;
    it = factory.find(name);
    if (it != factory.end()) {
        return factory.find(name)->second->create();
    }
    return nullptr;

}


//int main() {
//    map<string, creator*> myFactory;
//    myFactory.insert(pair<string, creator*>("manager", new managerCreator()));
//    myFactory.insert(pair<string, creator*>("headTeam", new headTeamCreator()));
//    myFactory.insert(pair<string, creator*>("simpleWorker", new simpleWorkerCreator()));
//
//    worker *boss = findInMyFactory("manager", myFactory);
//    worker *simpleWorker1 = findInMyFactory("simpleWorker", myFactory);
//    worker *simpleWorker2 = findInMyFactory("simpleWorker", myFactory);
//    boss->print();
//    simpleWorker1->print();
//    simpleWorker2->print();
//
//}