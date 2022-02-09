#include <iostream>

using namespace std;


class Adaptee {
public:
    virtual void functionality() {
        cout << "Adaptee functionality" << endl;

    }
};

class Task {
public:
    virtual void makeTask() {
        cout << "make task";

    };
};

class specificAdaptee : public Adaptee {
public:
    void functionality() override {
        cout << "specific Adaptee functionality" << endl;
    }

};


class specificTask : public Task {
private:
    Adaptee *adaptee;
public:
    specificTask(Adaptee *adaptee) : Task(), adaptee(adaptee) {};

    void makeTask() override {
        Task::makeTask();
        cout << " - in  the specificTask" << endl;
        adaptee->functionality();
    }
};

//int main() {
//    specificAdaptee adaptee1 =specificAdaptee();
//    specificTask t1(&adaptee1);
//    t1.makeTask();
//}
