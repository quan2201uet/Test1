#ifndef DECORATOR_H
#define DECORATOR_H

#include <string.h>
#include <iostream>

using namespace std;

class Beverage
{
public:
    virtual ~Beverage()= default;
    virtual string getDiscription() = 0;
    virtual double cost() = 0;

};

class chocolatte : public Beverage
{
public:
    string getDiscription() override;
    double cost() override;

};


class Socola : public Beverage
{
private:
    Beverage* beverage;
public:
    Socola(Beverage* bev);
    string getDiscription() override;
    double cost() override;
};

#endif // DECORATOR_H
