# include <iostream>
#include <vector>

using namespace std;
class people;

class crowd {
protected:
    string name;
    string lookAt;
public:

    crowd(string name,string lookAT) : name(name), lookAt(lookAT){}
    virtual void update(people* p) {};
    string getName(){
        return name;
    }
};


class people {
protected:
    vector<crowd *> observers;
    string name;
    string state;
public:
    people(string theName) : name(theName) {};

    void addObserver(crowd *person) {
        observers.push_back(person);
    }

    void removeObserver(crowd *person) {
        for (int i = 0; i < observers.size(); i++) {
            if (observers[i]->getName() == person->getName()) {
                observers.erase(observers.begin() + i);
            }
        }
    }

    void setState(string theState) {
        state = theState;
        notify();
    }
    string getState() {
        return state;
    }
    string getName() {
        return name;
    }

    void notify() {
        cout<<name<<" is "<<state<<" :"<<endl;
        for (crowd *c: observers) {
            c->update(this);
        }
    }

};
class mother : public crowd {

public:
    mother(string name,string lookAt) : crowd(name,lookAt) {};
    void update(people* p) {
        if(p->getName()==lookAt){
            if(p->getState()=="falling"){
                cout<<"the mom said: ohh my baby!!!"<<endl;
            }
            if(p->getState() == "dunking"){
                cout<<"the mom said:  this is my son!!"<<endl;

            }
            if(p->getState() == "scored a three"){
                cout<<"the mom said wonderful"<<endl;

            }
        }
        else if(p->getState() == "falling"){
            cout<<"some women say: poor boy"<<endl;
        }

    }
};
class headHunter : public crowd {

public:
    headHunter(string name,string lookAt) : crowd(name,lookAt) {}
    void update(people* p){
        if(p->getName()==lookAt){
            if(p->getState()=="falling"){
                cout<<"the head Hunter say: he is too weak hahaha.."<<endl;
            }
            if(p->getState() == "dunking"){
                cout<<"the head Hunter say: great!!"<<endl;

            }
            if(p->getState() == "scored a three"){
                cout<<"the head Hunter say: it is not stirring "<<endl;

            }
        }
        else if(p->getState() == "dunking"){
            cout<<"the head Hunter say: maybe i need to look at him, wonderful!"<<endl;
        }

    }
};

class player : public people {
public:
    player(string name) : people(name) {};
};

//int main(){
//    crowd *momOfJor=new mother("momOfJor","jordan");
//    crowd *headHu= new headHunter("headHun","jordan");
//    crowd *momOfnash=new mother("momOfJor","nash");
//    people *playNumber23=new player("jordan");
//    people *playNumber18=new player("nash");
//    playNumber18->addObserver(headHu);
//    playNumber18->addObserver(momOfJor);
//    playNumber18->addObserver(momOfnash);
//    playNumber23->addObserver(momOfJor);
//    playNumber23->addObserver(headHu);
//
//    playNumber23->setState("dunking");
//    cout<<"****************************************"<<endl;
//    playNumber18->setState("falling");
//}