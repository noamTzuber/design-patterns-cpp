# include <iostream>
# include  <vector>


using namespace std;
// change the vector in the father//
class component{
protected:
    string name;
public:
    component(string name){
        this->name=name;
    }
    virtual void telYourName(){}
    virtual void addChild(component *a){}
    void removeChild(component *a){}

};
class father: public component{
    vector<component*> children;
public :
    father(string name): component(name){}

    virtual void telYourName(){
        cout<<name<<endl;
        for(component* c : children){
            c->telYourName();
        }
    }
    void addChild(component *a){
        this->children.push_back(a);
    }

};

class child: public component{
public:
    child(string name): component(name){}

    void telYourName() override{
        cout<<name<<endl;
    }
};

int main(){
    component *a=new father("ari");
    component *b= new child("ben");
    a->addChild(b);
    a->telYourName();
    return 0;
}

