#include <iostream>
using namespace std;
class Int {
public:
    int num;

    // simple constructor
    Int(int c) {
        num = c;
    }

    // copy constructor
    Int(Int &t) {
        this->num = t.num;
    }

    // plus operator object in the left
    int operator+(int i) {
        return this->num * 2 + i;
    }

    // right ++(in the end)
    Int operator++(int i) {
        cout << "before" << endl;
        Int tmp(*this);
        this->num += 1;
        return tmp;
    }

    //left ++(in the start)
    Int &operator++() {
        cout << "after" << endl;
        this->num += 1;
        return *this;
    }


};

// plus operator object in the right
int operator+(int i, Int num) {
    return num.num + i;
}

int main() {

    Int x(5);
//Int y=Int(5);
//int res =4+y;
    cout << (x++).num << endl;
    cout << (++x).num << endl;

    return 0;
}