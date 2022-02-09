#include <iostream>

using namespace std;

class Point3D {
public:
    int x;
    int y;
    int z;

    Point3D(int x, int y, int z) : x(x), y(y), z(z) {}
    Point3D(){
        this->x=0;
        this->y=0;
        this->y=0;
    };
    void print(){
        cout<<"( "<<x<<","<<y<<","<<z<<" )"<<endl;
    }
    Point3D& operator=(Point3D p){
        this->x=p.x;
        this->y=p.y;
        this->y=p.y;
    }

};

class comparetor {
public:
    comparetor() {};
    virtual bool  compare(Point3D x, Point3D x1) {
         return 0;
     };
};

class Xcompare : public comparetor{
public:
    Xcompare():comparetor(){};
    bool virtual compare(Point3D x, Point3D x1) {
        return x.x>x1.x;
    }

};

class sort {
public:
    comparetor *c;
    sort(comparetor* c) {
        this->c = c;
    }
    virtual void doSort(Point3D *array, int size) {};

};
class bubbleSort : public sort {
public:
    bubbleSort(comparetor *c) : sort(c) {};
    void doSort(Point3D array[], int size) override {
        int i, j;
        for (i = 0; i < size - 1; i++)
            // Last i elements are already in place
            for (j = 0; j < size - i - 1; j++)
                if (c->compare(array[j], array[j + 1]))
                    swap(&array[j], &array[j + 1]);
    }
    void swap(Point3D *xp, Point3D *yp) {
        Point3D temp = *xp;
        *xp = *yp;
        *yp = temp;
    }

};
class insertioneSort : public sort {
public:
    insertioneSort(comparetor* c) : sort(c) {};

    void doSort(Point3D arr[], int n){
        int i, j;
        Point3D  key=Point3D();
        for (i = 1; i < n; i++){
            key = arr[i];
            j = i - 1;

            while ((j >= 0) && c->compare(arr[j], key)){
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
};


class Ycompare : public comparetor{
public:
  Ycompare():comparetor(){};
    bool virtual compare(Point3D x, Point3D x1) {
      return x.y>x1.y;
  }

};
class Zcompare : public comparetor{
public:
    Zcompare():comparetor(){};
    bool virtual compare(Point3D x, Point3D x1) {
        return x.z>x1.z;
    }
};

//checking polimotfizem
//int main(){
//    Point3D arr[]={Point3D(100,0,100),Point3D(2,4,9),Point3D(3,3,11)};
//    sort* s= new bubbleSort(new Xcompare);
//    s->doSort(arr,3);
//    for(int i=0;i<3;i++){
//        arr[i].print();
//
//    }
//    cout<<"finish bubbleSort by x"<<endl;
//
//    s= new bubbleSort(new Ycompare);
//    s->doSort(arr,3);
//    for(int i=0;i<3;i++){
//        arr[i].print();
//    }
//    cout<<"finish bubbleSort by y"<<endl;
//
//    s= new insertioneSort(new Xcompare);
//    s->doSort(arr,3);
//    for(int i=0;i<3;i++){
//        arr[i].print();
//    }
//    cout<<"finish insertionSort by x"<<endl;
//
//
//    s= new insertioneSort(new Ycompare);
//    s->doSort(arr,3);
//    for(int i=0;i<3;i++){
//        arr[i].print();
//    }
//    cout<<"finish insertionSort by y"<<endl;
//
//
//    return 0;
//}
