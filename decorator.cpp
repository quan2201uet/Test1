#include "decorator.h"


// class chocolatte
string chocolatte :: getDiscription()
{
    return "Chocolatte";
}

double chocolatte :: cost()
{
    return 2.5;
}

// class socola

Socola :: Socola(Beverage* bev) : beverage(bev){}

string Socola :: getDiscription()
{
    return beverage->getDiscription() + " + Socola";
}

double Socola :: cost()
{
    return beverage->cost() + 0.5;
}
