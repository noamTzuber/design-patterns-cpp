#include <iostream>
using namespace std;

class Pizza{
public:
    Pizza(){}
    virtual void printMySelf()=0;
};

class decorator: public Pizza{
protected:
    Pizza * pizza;
    decorator(Pizza *comp): Pizza(){
        this->pizza=comp;
    }
    virtual void printMySelf() {
        pizza->printMySelf();
        addBehavior();
    }
    virtual void addBehavior()=0;

};

class mashrooms : public decorator{
public:
    mashrooms(Pizza * comp): decorator( comp){}
    void addBehavior(){
        cout<<"mashrooms"<<endl;
    }


};
class extraCheese : public decorator{
public:
    extraCheese(Pizza * comp): decorator(comp){}
    void addBehavior(){
        cout<<"extraCheese"<<endl;
    }
};
class olives : public decorator{
public:
    olives(Pizza * comp): decorator(comp){}
    void addBehavior(){
        cout<<"olives"<<endl;
    }
};

class bigPizza: public  Pizza{
public:
    bigPizza(): Pizza(){}
    void printMySelf(){
        cout<<"bigPizza"<<endl;
    }
};
class mediumPizza: public  Pizza{
public:
    mediumPizza(): Pizza(){}
    void printMySelf(){
        cout<<"mediumPizza"<<endl;
    }
};

class smallPizza: public  Pizza{
public:
    smallPizza(): Pizza(){}
    void printMySelf(){
        cout<<"smallPizza"<<endl;
    }
};
//
//int main(){
//    Pizza *a=new olives(new extraCheese(new mashrooms(new mediumPizza)));
//    a->printMySelf();
//    return 0;
//}