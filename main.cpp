#include <iostream>

using namespace std;

class FlyBehavior
{
public:
    virtual void fly() = 0; // khong cai phuong thuc chi dc cai trong cac lop con
    virtual ~FlyBehavior() = default; // tu dong giai phong tai nguyen khi doi tuong bi huy
};

class QuackBehavior
{
public:
    virtual void quack() = 0;
    virtual ~QuackBehavior() = default;
};

class FlyWithWings : public FlyBehavior
{
public:
    void fly() override
    {
        cout << "fly with wings " << endl;
    }
};

class FlyNoWay : public FlyBehavior
{
public:
    void fly() override
    {
        cout << "can't fly" << endl;
    }
};


class Quack : public QuackBehavior
{
public:
    void quack() override
    {
        cout << "Quack" << endl;
    }
};

class MuteQuack : public QuackBehavior
{
public:
    void quack() override
    {
        cout << "silence" << endl;
    }
};

class Duck
{
public:
    Duck(FlyBehavior* flybehavior, QuackBehavior* quackbehavior)
        : flybehavior(flybehavior), quackbehavior(quackbehavior){} // khoi tao thanh vien du lieu cua lop
    virtual void Display() = 0;

    void PerformFly()
    {
        flybehavior->fly();
    }

    void PerformQuack()
    {
        quackbehavior->quack();
    }

    virtual ~Duck() = default;

protected:
    FlyBehavior* flybehavior;
    QuackBehavior* quackbehavior;
};


class MallardDuck : public Duck
{
public:
    MallardDuck() : Duck(new FlyWithWings(), new Quack()){}
    void Display() override
    {
        cout << " i`m a MallardDuck" << endl;
    }

};

class ModelDuck : public Duck
{
public:
    ModelDuck() : Duck(new FlyNoWay(), new MuteQuack()){}
    void Display() override
    {
        cout << "i'm a ModelDuck" << endl;
    }
};

int main()
{
 Duck* mallard = new MallardDuck();
 mallard->Display();
 mallard->PerformFly();
 mallard->PerformQuack();
 cout << endl;
 Duck* model = new ModelDuck();
 model->Display();
 model->PerformFly();
 model->PerformQuack();

 return 0;
}
