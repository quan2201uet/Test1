#include<iostream>
#include<string>
using namespace std;

class Pizza
{
public:
    virtual void prepare() = 0;
    virtual void bake(){cout << "baking......." << endl;}
    virtual void box(){cout << "boxing......." << endl;}
    virtual ~Pizza() = default;
};

class cheesePizza : public Pizza
{
public:
    void prepare() override
    {
        cout << "preparing with cheese" << endl;
    }
};

class salatPizza : public Pizza
{
public:
    void prepare() override
    {
        cout << "preparng with salat" << endl;;
    }
};

class simplePizzaFactory
{
public:
    Pizza* createPizza(const string &type)
    {
        if (type == "cheese"){return new cheesePizza();}
        else if(type == "salat"){return new salatPizza();}
        else return nullptr;
    }
};

class pizzaStore
{
private:
    simplePizzaFactory* factory;
public:
    pizzaStore(simplePizzaFactory* mFactory) : factory(mFactory){}

    Pizza* orderPizza(const string &type)
    {
        Pizza* pizza = factory->createPizza(type);
        if (pizza == nullptr){
            cout << "khong co order" << endl;
            return nullptr;
        }
        pizza->prepare();
        pizza->box();
        pizza->bake();
        return pizza;
    }
};

int main()
{
    simplePizzaFactory factory;
    pizzaStore store(&factory);

   cout << "order cheese pizza" << endl;
   Pizza* pizza1 = store.orderPizza("cheese");

   if(pizza1) delete pizza1;

   cout << ".......................\n";
   cout << "order salat pizza" << endl;
   Pizza* pizza2 = store.orderPizza("salat");
   if (pizza2) delete pizza2;
   return 0;
}

