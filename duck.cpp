#include "duck.h"


void FlyWithWings :: fly(){cout << "fly with wings " << endl;}


void FlyNoWay :: fly(){cout << "can't fly" << endl;}


void Quack :: quack() { cout << "Quack" << endl;}

void MuteQuack :: quack() {cout << "silence" << endl;}


Duck :: Duck(FlyBehavior* flybehavior, QuackBehavior* quackbehavior)
    : mFlybehavior(flybehavior), mQuackbehavior(quackbehavior){}

void Duck :: PerformFly(){ mFlybehavior->fly();}

void Duck :: PerformQuack() {mQuackbehavior->quack();}

MallardDuck :: MallardDuck() : Duck(new FlyWithWings(), new Quack()){}

void MallardDuck :: Display() {cout << "i`m a MallardDuck" << endl;}

ModelDuck :: ModelDuck() : Duck(new FlyNoWay(), new MuteQuack()){}

void ModelDuck :: Display(){cout << "i'm a ModelDuck" << endl;}
