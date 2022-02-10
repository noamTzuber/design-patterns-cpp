#include <iostream>
using namespace std;

class abstractTreeNode {
public:
    abstractTreeNode(){};
    virtual int interpret(){};
};

class treeLeaf :public abstractTreeNode{
    int x;
public:
    treeLeaf(int x):abstractTreeNode(), x(x){};
    int interpret() {
        return this->x;
    }
};
class binaryNode : public abstractTreeNode{
protected:
    abstractTreeNode * left;
    abstractTreeNode * right;
public:
    binaryNode( abstractTreeNode * left,abstractTreeNode * right):
    abstractTreeNode(),left(left),right(right){};

    virtual int interpret() override=0;
};

class minusNode: public binaryNode{
public:
    minusNode(abstractTreeNode * left,abstractTreeNode * right): binaryNode(left,right){};
    int interpret() override{
        return left->interpret() - right->interpret();
    }
};
class plusNode: public binaryNode{
public:
    plusNode(abstractTreeNode * left, abstractTreeNode * right): binaryNode(left,right){};
    int interpret() override{
        return left->interpret() + right->interpret();
    }
};
class divideNode: public binaryNode{
public:
    divideNode(abstractTreeNode * left,abstractTreeNode * right): binaryNode(left,right){};
    int interpret() override{
        return left->interpret() / right->interpret();
    }
};
class timesNode: public binaryNode{
public:
    timesNode(abstractTreeNode * left,abstractTreeNode * right): binaryNode(left,right){};
    int interpret() override{
        return left->interpret() * right->interpret();
    }
};

//int main(){
//    abstractTreeNode * equation=new timesNode(new plusNode(new treeLeaf(5),new treeLeaf(5)),new treeLeaf(10));
//    cout<<equation->interpret()<<endl;
//}