#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h>

using namespace std;
class singleton;

class instance {

    friend singleton;
    int x;
    instance() {
        // saving random number
        srand((unsigned) time(0));
        x=(rand() % 100) + 1;
    };
public:
    void print(){
        // print the random number - it always the same
        cout<<x<<endl;
    }
};

class singleton {
    static instance *ins;
public:
    static instance *getInstance() {
        if (ins == nullptr) {
            // checking how many time we pass in the creator (just one!!)
            cout << "create the object" << endl;
            ins = new instance();
        }
        return ins;
    };

};

//because instance will be initialized on demand.
instance * singleton::ins = 0 ;

//int main()
//{
//    instance* s = singleton::getInstance();
//    // will not print the "creat object"
//    instance* r = singleton::getInstance();
//    r->print();
//    s->print();
//return 0;
//}