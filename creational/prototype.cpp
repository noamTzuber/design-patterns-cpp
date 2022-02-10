#include <iostream>
using namespace std;

class shape{
public:
    shape(){};
    virtual shape* clone()=0;
    virtual void print ()=0;
};

class tringle : public shape{
protected:
    int x;
    int y;
    int z;
    tringle(int x, int y ,int z): shape() ,x(x),y(y),z(z){};
    tringle* clone(){
        new tringle(x,y,z);
    }
    void print (){
        cout<<"my corners are: "<<x<<y<<z<<endl;
    }
};

class circle : public shape{
protected:
    int x;
    int y;
    int radius;
public:
    circle(int x, int y ,int radius): shape() ,x(x),y(y),radius(radius){};
    circle* clone(){
        new circle(x,y,radius);
    }
    void print (){
        cout<<"my center is:"<<x<<y<<" my radius is: "<<radius<<endl;
    }
};

//int main (){
//    shape * myShape=new circle(0,0,2);
//    shape * hisShape =myShape->clone();
//    hisShape->print();
//    return 0;
//}