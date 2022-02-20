#include <iostream>
#include <ctime>
#include <stdlib.h>


using namespace std;

class singleton;

class singleton {
    static singleton *ins;
    int random_variable;

    singleton() {
        srand(time(0));
        random_variable = rand();
    }

public:
    static singleton *getInstance() {
        if (ins == nullptr) {
            // checking how many time we pass in the creator (just one!!)
            cout << "create the object" << endl;
            ins = new singleton();
        }
        return ins;
    };

    void print() {
        cout << this->random_variable << endl;

    }

};

//because instance will be initialized on demand.
singleton *singleton::ins = 0;

int main() {
    singleton *s = singleton::getInstance();
    // will not print the "creat object"
    singleton *r = singleton::getInstance();
    r->print();
    s->print();
    return 0;
}
