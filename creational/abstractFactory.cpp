#include <iostream>
# include <map>

using namespace std;

class pants{
public:
    pants(){};
    virtual void print()=0;
    virtual ~pants(){};
};
class jacket {
public:
    jacket() {};

    virtual void print() = 0;
};

class abstractFactory{
public:
    abstractFactory(){};
    virtual pants* createPants()=0;
    virtual jacket* createJacket()=0;
};

class elegantPants:public  pants{
public:
    elegantPants():pants(){}
    void print(){
        cout<<"elegantPants"<<endl;

    }
    ~elegantPants(){};
};
class workPants: public pants{
public:
    workPants():pants(){}
    void print(){
        cout<<"workPants"<<endl;

    }


};

class elegantJacket: public jacket{
public:
    elegantJacket():jacket(){};
    virtual void print(){
        cout<<"elegantJacket"<<endl;
    }
};
class workJacket: public jacket{
public:
    workJacket():jacket(){};
    virtual void print(){
        cout<<"workJacket"<<endl;
    }
};


class elegant :public abstractFactory{

public:
    elegant():abstractFactory(){};
    virtual  pants* createPants(){
        return new elegantPants;
    }
    virtual jacket* createJacket(){
        return new elegantJacket;
    }

};

class work :public abstractFactory{

public:
    work():abstractFactory(){};
    virtual pants* createPants(){
        return new workPants;
    }
    virtual jacket* createJacket(){
        return new workJacket;
    }

};

//int main(){
//
//    abstractFactory *AdamClothes= new elegant();
//    pants *AdamPants=AdamClothes->createPants();
//    jacket *AdamJacket=AdamClothes->createJacket();
//    cout<<"adam clothes are:"<<endl;
//    AdamPants->print();
//    AdamJacket->print();
//
//    abstractFactory *benClothes = new work();
//    pants *benPants=benClothes->createPants();
//    jacket *benJacket=benClothes->createJacket();
//    cout<<"ben clothes are:"<<endl;
//    benPants->print();
//    benJacket->print();
//// delete all the new...
//    delete benPants;
//return 0;
//}