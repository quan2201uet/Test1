#include <iostream>
#include <string>
using namespace  std;

class Beverage
{
public:
    virtual string getDiscription() = 0;
    virtual double cost() = 0;
    virtual ~Beverage(){}
};

class Espresso : public Beverage
{
public:
    string getDiscription() override {return "espresso";}
    double cost() override {return 2.9;}
};

class Mocha : public Beverage
{
private:
    Beverage* beverage;
public:
    Mocha(Beverage* bev): beverage(bev){}
    string getDiscription() override
    {
        return beverage->getDiscription() + ", Mocha";
    }
    double cost() override
    {
        return beverage->cost()+0.5;
    }
};

int main()
{
    Beverage* beverage = new Espresso();
    cout << "Discription: " << beverage->getDiscription() << ", cost: " << beverage->cost();
    Mocha* mocha = new Mocha(beverage);
    cout << "Discription: " << mocha->getDiscription() << ", cost: " << mocha->cost();
    return 0;
}
