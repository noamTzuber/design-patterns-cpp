#include <iostream>

using namespace std;

class state;


class state {
public:
    virtual void move(){};
};


class robot {
protected:
    string myName;
    state *sta;
public:
    robot(string name, state *st) : myName(name), sta(st) {};
    void move(){
        sta->move();
    };
};

class healthy : public state {
public:
    healthy(): state(){};
    void move() {
        cout << " im healthy i can run" << endl;
    }
};

class faulty : public state {
public:
    faulty(): state(){};
    void move() {
        cout << " im faulty i barely can walk." << endl;
    }
};

//int main() {
//    state *weak = new faulty();
//    robot * Robot = new robot("Yishmael", weak);
//    Robot->move();
//    return 0;
//}