#include <iostream>
#include "duck.h"
#include "decorator.h"

int main()
{
// Duck* mallard = new MallardDuck();
// mallard->Display();
// mallard->PerformFly();
// mallard->PerformQuack();
// cout << endl;
// Duck* model = new ModelDuck();
// model->Display();
// model->PerformFly();
// model->PerformQuack();

    Beverage* beverage = new chocolatte();
    cout << "Beverage: " << beverage->getDiscription() << ", $: " << beverage->cost();
    cout << endl;
    Socola* socola = new Socola(beverage);
    cout << "Beverage: " << socola->getDiscription() << ", $: " << socola->cost();
    cout << endl;
 return 0;
}
