#include <iostream>
using namespace std;
#include "map"
class priceCalculation{
public:
    virtual int calculate(int price)=0;
};
class happyHour: public priceCalculation{
public:
    int calculate(int x){
        return x/2;
    }
};
class austerityPeriod: public priceCalculation{
public:
    int calculate(int x){
        return x*2;
    }
};
class regularTime: public priceCalculation{
public:
    int calculate(int x){
        return x;
    }
};




class market {
private:
    priceCalculation * p;
    map<string ,int> priceTable;
public:
    market(priceCalculation * p): p(p){};
    void addProduct(string name, int price){
        priceTable.insert(pair<string,int>(name, price));
    }
    void printPrices(){
        for(auto c :priceTable){
            cout<<c.first<<": "<<p->calculate(c.second)<<endl;
        }
    }
    void setPriceCalculation(priceCalculation *pt){
        p=pt;
    }

};

//int main (){
//    market *Market = new market(new regularTime);
//    Market->addProduct("banana", 20);
//    Market->addProduct("apple", 10);
//    Market->addProduct("chicken", 30);
//    cout<<"in regular times: "<<endl;
//    Market->printPrices();
//    Market->setPriceCalculation(new austerityPeriod);
//    cout<<endl<<"in austerity Period:"<<endl;
//    Market->printPrices();
//    Market->setPriceCalculation(new happyHour);
//    cout<<endl<<"in the happy hour:"<<endl;
//    Market->printPrices();
//}