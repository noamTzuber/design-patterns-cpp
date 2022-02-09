#include <iostream>
#include <map>

using namespace std;

class flyWeight {

public:
    flyWeight() {};

    virtual void print(int x, int y) {};

};

class soldier : public flyWeight {
public:
    soldier() : flyWeight() {};

    void print(int x, int y) {
        cout << "soldier in " << x << "/" << y << endl;
    }
};


class tank : public flyWeight {
public:
    tank() : flyWeight() {};

    void print(int x, int y) {
        cout << "tank in " << x << "/" << y << endl;
    }
};

class myCharacter {
public:
    int row;
    int col;
    flyWeight *fly;

    myCharacter(int row, int col, flyWeight *fly) : row(row), col(col), fly(fly) {};

    void print() {
        fly->print(row, col);
    }
};

class factoryFlyWeight {
public:
    factoryFlyWeight() {};

    flyWeight *getFly(map<string, flyWeight *> &currentObjects, string name) {
        // checking if is exist in map
        auto exist = currentObjects.find(name);

        // if exist the mad dont return end-> we go the second the place of pointer.
        if (exist != currentObjects.end()) {
            return currentObjects.find(name)->second;
        } else {
            //if it soldier create and return
            if (name == "soldier") {
                std::pair<std::string, flyWeight *> p(name, new soldier());
                currentObjects.insert(p);
                return currentObjects.find(name)->second;
            }
            //if it tank create and return
            if (name == "tank") {
                flyWeight *a = new tank();
                pair<string, flyWeight *> p(name, a);
                currentObjects.insert(p);
                return a;
            }

        }
    };
};

//int main() {
//    map<string, flyWeight *> currentObjects;
//    factoryFlyWeight factory;
//    myCharacter one = myCharacter(1, 2, factory.getFly(currentObjects, "soldier"));
//    myCharacter second = myCharacter(9, 9, factory.getFly(currentObjects, "soldier"));
//    myCharacter third=myCharacter(3,6,factory.getFly(currentObjects,"tank"));
//    one.print();
//    second.print();
//    third.print();
//    return 0;
//}