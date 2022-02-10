# include <iostream>
# include <vector>

using namespace std;

class meal {
public:
    bool isCuted = false;
    bool isCooked = false;
    bool isMixed = false;
    bool isBaked = false;

    meal(){};
    void print(){
        cout<<"is cutted? "<< isCuted<<endl;
        cout<<"is cooked? "<< isCooked<<endl;
        cout<<"is mixed? "<< isMixed<<endl;
        cout<<"is baked? "<< isBaked<<endl;
    }
};

class command {
protected:
    meal *m;
public:
    command(meal *m):m(m){};

    virtual void excute() {};
};

class cut : public command {
public :
    cut(meal *m) : command(m) {}
    void excute() override {
        m->isCuted = true;
    }
};

class mix : public command {
public :
    mix(meal *m) : command(m) {}

    void excute() override {
        m->isMixed = true;
    }
};

class bake : public command {
public :
    bake(meal* m):
    command(m){}

    void excute() override {
        m->isBaked = true;
    }
};
class cook : public command {
public :
    cook(meal* m):
    command(m){}

    void excute() override {
        m->isCooked = true;
    }
};

class maker{
public:
    vector <command*>listCommand;
    maker(){}
    void addCommand(command * c){
        listCommand.push_back(c);
    }
    void excute(){
        for(command * c:listCommand){
            c->excute();
        }
    }
};

//int main(){
//
//    meal *m= new meal();
//    maker *Maker=new maker();
//    Maker->addCommand( new cut(m));
//    Maker->addCommand(new bake(m));
//    Maker->excute();
//
//    m->print();
//
//}