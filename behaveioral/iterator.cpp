#include <iostream>

using namespace std;

class doubleIterator;

class structure {
public:
    int *arr1;
    int *arr2;
    int size1;
    int size2;

    structure(int *arr1, int *arr2, int size1, int size2) : arr1(arr1), arr2(arr2), size1(size1), size2(size2) {};

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

class Iterator {
protected:
    structure *structure;
public:
    Iterator(class structure *structure1) : structure(structure1) {};

    virtual int *begin()=0;

    virtual int *end() =0;

    virtual int *next()=0;

    virtual int *currentItem()=0;


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
    doubleIterator(class structure *structure1) : Iterator(structure1) {
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

    int *begin() {
        return this->beginValue;
    }

    int *end() {
        return this->endValue;
    }

    int *currentItem() {
        return this->current;
    }

    int *next() {
        // if we in the end of the array
        if (current == endValue) {
            cout << "end of arrays" << endl;
            // if it is the first value
        } else if (current == beginValue) {
            int long long placeInArr = (current - arr1) ;
            current = arr2 + placeInArr;
            // if we are in first array move to the second - at the same place
        } else if (current >=arr1 && current <= arr1+ size1) {
            int long long placeInArr = (current - arr1)  ;
            current = arr2 + placeInArr ;
            // if we are in the second array move the first and move on one variable
        } else {
            int long long placeInArr = (current - arr2) ;
            current = arr1 + placeInArr + 1;
        }
        return
                current;
    };

};

class dataStructure : public structure {
protected:
    int *arr1;
    int *arr2;
    int size1;
    int size2;
public:
    dataStructure(int *arr1, int *arr2, int size1, int size2) : structure(arr1, arr2, size1, size2), arr1(arr1),
                                                                arr2(arr2), size1(size1), size2(size2) {}

    doubleIterator *createIterator() {
        return new doubleIterator(this);
    };
};


int main() {

    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    doubleIterator it = *(new dataStructure(arr1, arr2, 3, 3))->createIterator();
    for (int i; i < 6; i++) {
        cout << *(it.currentItem()) << endl;
        it.next();
    }
    return 0;
}
