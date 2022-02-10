#include <iostream>
#include "map"
using namespace std;

class market {
protected:
    map<string ,int> priceTable;
public:
    void addProduct(string name, int price){
        priceTable.insert(pair<string,int>(name, price));
    }
    virtual void printPrices()=0;

};
class marketHappyHour :public market{
public:
    void addProduct(string name, int price){
        priceTable.insert(pair<string,int>(name, price));
    }
    void printPrices(){
        for(auto c :priceTable){
            cout<<c.first<<": "<<c.second/2<<endl;
        }
    }

};
class marketAusterityPeriod :public market{
public:
    void addProduct(string name, int price){
        priceTable.insert(pair<string,int>(name, price));
    }
    void printPrices(){
        for(auto c :priceTable){
            cout<<c.first<<": "<<c.second*2<<endl;
        }
    }

};
class marketRegularPeriod :public market{
public:
    void addProduct(string name, int price){
        priceTable.insert(pair<string,int>(name, price));
    }
    void printPrices(){
        for(auto c :priceTable){
            cout<<c.first<<": "<<c.second<<endl;
        }
    }

};

int main (){
    market *RegularMarket = new marketRegularPeriod();
    RegularMarket->addProduct("banana", 20);
    RegularMarket->addProduct("apple", 10);
    RegularMarket->addProduct("chicken", 30);
    market *austerityMarket = new marketAusterityPeriod();
    austerityMarket->addProduct("banana", 20);
    austerityMarket->addProduct("apple", 10);
    austerityMarket->addProduct("chicken", 30);

    cout<<"in regular times: "<<endl;
    RegularMarket->printPrices();

    cout<<endl<<"in austerity Period:"<<endl;
    austerityMarket->printPrices();

}