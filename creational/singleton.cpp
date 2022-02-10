#include <iostream>
using namespace std;


class Singleton
{
private:
    /* Here will be the instance stored. */
    static Singleton* instance;
    string name;
    int age;
    string professionalism;

    /* Private constructor to prevent instancing. */
    Singleton(){
        this->name="david";
        this->age =48;
        this->professionalism="president";
    };

public:
    /* Static access method. */
    static Singleton* getInstance(){
        if (instance == 0)
        {
            cout<<"create the object"<<endl;
            instance = new Singleton();
        }

        return instance;
    };
    void printDetails(){
        cout<<"the name is: "<< this->name<<endl<<"his age is: "<<this->age<<endl<<
        "his professionalism is: "<< this->professionalism<<endl;
    }
};

/* Null, because instance will be initialized on demand. */
Singleton* Singleton::instance = 0;

int main()
{
    //new Singleton(); // Won't work
    Singleton* s = Singleton::getInstance(); // Ok
    Singleton* r = Singleton::getInstance();
    r->printDetails();

}