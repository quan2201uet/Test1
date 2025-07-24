#ifndef DUCK_H
#define DUCK_H

#include <iostream>
using namespace std;

class FlyBehavior {
public:
    virtual void fly() = 0;
    virtual ~FlyBehavior() = default;
};

class QuackBehavior {
public:
    virtual void quack() = 0;
    virtual ~QuackBehavior() = default;
};

class FlyWithWings : public FlyBehavior {
public:
    void fly() override;
};

class FlyNoWay : public FlyBehavior {
public:
    void fly() override;
};

class Quack : public QuackBehavior {
public:
    void quack() override;
};

class MuteQuack : public QuackBehavior {
public:
    void quack() override;
};

class Duck {
public:
    Duck(FlyBehavior* flybehavior, QuackBehavior* quackbehavior);
    virtual void Display() = 0;
    void PerformFly();
    void PerformQuack();
    virtual ~Duck() = default;

protected:
    FlyBehavior* mFlybehavior;
    QuackBehavior* mQuackbehavior;
};

class MallardDuck : public Duck {
public:
    MallardDuck();
    void Display() override;
};

class ModelDuck : public Duck {
public:
    ModelDuck();
    void Display() override;
};

#endif // DUCK_H
