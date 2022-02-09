#include <iostream>

using namespace std;

class Int {
public:
    int num;

    // simple constructor
    Int(int c) {
        num = c;
    }

    // copy constructor -reuse in copy operator
    Int(Int &t) {
        *this = t;
        cout << "copy constructor" << endl;
    }

    // move constructor- reuse in move operator
    Int(Int &&old) {
        *this = move(old);
        cout << "move constructor" << endl;
    }

    // copy operator
    Int &operator=(Int &original) {
        // checking if their addresses are the same
        if (this != &original) {
            this->num = original.num;
            cout << "copy operator" << endl;
        }
        return *this;
    }

    // move operator
    Int &operator=(Int &&original) {
        this->num = original.num;
        cout << "move operator" << endl;
        return *this;
    }

    ~Int() = default;


    // plus operator object in the left
    int operator+(int i) {
        return this->num * 2 + i;
    }

    // right ++(in the end)
    Int operator++(int i) {
        cout << "add the num before the current command:" << endl;
        Int tmp(*this);
        this->num += 1;
        return tmp;
    }

    //left ++(in the start)
    Int &operator++() {
        cout << "add the num after the current command:" << endl;
        this->num += 1;
        return *this;
    }

};

template<class T, class func>
T function(T &a, const func &f) {
    return f(a);
}



int main() {

    //// the ++ before and after
//    Int x(5);
//    cout << (x++).num << endl;
//    cout << (++x).num << endl;
////****************************************
    //// using move and copy constructor and operators
//    Int x(5);
//    Int t=move(x);
//    Int y =x;
////****************************************
    float a = 4.44;
    int y = 9;
    // lambda function
    float res = function(a, [&y](float param) { return param * 100 + y; });
    cout << "the number after template function is " << res << endl;
////****************************************

    return 0;
}