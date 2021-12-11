#include <iostream>
#include <string>
#include "factory.hpp"

class Bakery
{
public:
    virtual std::string GetName() = 0;
};

class Donut: public Bakery
{
    std::string name = "Donut";
public:
    std::string GetName() override
    {
        return name;
    }

    static Donut* Make()
    {
        return new Donut();
    }
};

class Pudding:public Bakery
{
    std::string name="Pudding";
public:
    std::string GetName() override
    {
        return name;
    }

    static Pudding* Make()
    {
        return new Pudding();
    }
};

int main()
{
    Factory<Bakery>::Register("Donut", Donut::Make);
    Factory<Bakery>::Register("Pudding", Pudding::Make);
    auto d = Factory<Bakery>::Make("Donut");
    auto p = Factory<Bakery>::Make("Pudding");

    std::cout << d->GetName() << std::endl << p->GetName() << std::endl;
}