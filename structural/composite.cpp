# include <iostream>
# include  <vector>


using namespace std;

class composite{
protected:
    vector<composite*> children;
    string name;
public:
    composite(string name){
        this->name=name;
    }
    virtual void telYourName(){}
    void addChild(composite *a){
        this->children.push_back(a);
    }
    void removeChild(composite *a){
        //do something
    }

};
class father: public composite{
public :
    father(string name): composite(name){}

    virtual void telYourName(){
        cout<<name<<endl;
        for(composite* c : children){
            c->telYourName();
        }
    }

};

class child: public composite{
public:
    child(string name): composite(name){}

    void telYourName() override{
        cout<<name<<endl;
    }
};

//int main(){
//    composite *a=new father("ari");
//    composite *b= new child("ben");
//    a->addChild(b);
//    a->telYourName();
//    return 0;
//}

