#include <iostream>

using namespace std;

class dataStructure;
class doubleIterator;

class Iterator {
protected:
    dataStructure *structure;
public:
    Iterator(dataStructure *structure) : structure(structure) {}

    virtual int *begin() {};

    virtual int *end() {};

    virtual int *next() {};

    virtual int *currentItem() {};


};

class dataStructure {
protected:
    int *arr1;
    int *arr2;
    int size1;
    int size2;
public:
    dataStructure(int *arr1, int *arr2, int size1, int size2) : arr1(arr1), arr2(arr2), size1(size1), size2(size2) {}
    doubleIterator *createIterator() {
//        return new doubleIterator(this);
    };

    int *getArr1() {
        return arr1;
    }

    int *getArr2() {
        return arr2;
    }

    int getSize1() {
        return size1;
    }

    int getSize2() {
        return size2;
    }
};

class doubleIterator : public Iterator {
    int *arr1;
    int *arr2;
    int size1;
    int size2;
    int *current;
    int *endValue;
    int *beginValue;
public:
    doubleIterator(dataStructure *structure) : Iterator(structure) {
        this->arr1 = structure->getArr1();
        this->arr2 = structure->getArr2();
        this->size1 = structure->getSize1();
        this->size2 = structure->getSize2();
        this->current = arr1;
        this->beginValue = arr1;
        if (this->size1 > this->size2) {
            this->endValue = arr1 + this->size1 - 1;
        } else {
            this->endValue = arr2 + this->size2 - 1;
        }
    }
        int * begin() {
            return this->beginValue;
        }

        int *end() {
            return this->endValue;
        }
        int *currentItem() {
            return this->current;
        }

        int *next() {
            if (current == endValue) {
                cout << "end of arrays" << endl;
            } else if (current >= arr1 && current < arr1 + size1) {
                int placeInArr2 = (current - arr1) / sizeof(int );
                current = arr2 + placeInArr2;
            } else {
                int placeInArr2 = (current - arr2) / sizeof(int );
                current = arr2 + placeInArr2 + 1;
            }
            return current;
        };

    };

//int main(){
//    int arr1[]={1,2,3};
//    int arr2[]={4,5,6};
//    Iterator it=*(new dataStructure(arr1,arr2,3,3))->createIterator();
//    cout<<*(it.begin())<<endl;
//    return 0;
//}
