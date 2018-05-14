#include <iostream>
#include <string>

class ProductA
{
    public:
        virtual std::string getName() = 0;
};

class ConcreteProductA1 : public ProductA
{
    public:
        std::string getName() override
        {
            return "A1";
        }
};

class ConcreteProductA2 : public ProductA
{
    public:
        std::string getName() override
        {
            return "A2";
        }
};

class ProductB
{
    public:
        virtual std::string getName() = 0;
};

class ConcreteProductB1 : public ProductB
{
    public:
        std::string getName() override
        {
            return "B1";
        }
};

class ConcreteProductB2 : public ProductB
{
    public:
        std::string getName() override
        {
            return "B2";
        }
};

class AbstractFactory
{
    virtual ProductA* createProductA() = 0;
    virtual ProductB* createProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory
{
    public:
        ProductA* createProductA() override
        {
            return new ConcreteProductA1();
        }
        ProductB* createProductB() override
        {
            return new ConcreteProductB1();
        }
};

class ConcreteFactory2 : public AbstractFactory
{
    public:
        ProductA* createProductA() override
        {
            return new ConcreteProductA2();
        }
        ProductB* createProductB() override
        {
            return new ConcreteProductB2();
        }
};

int main()
{
    ConcreteFactory1* factory1 = new ConcreteFactory1();
    ConcreteFactory2* factory2 = new ConcreteFactory2();

    ProductA* productA1 = factory1->createProductA();
    std::cout << productA1->getName() << std::endl;

    ProductB* productB1 = factory1->createProductB();
    std::cout << productB1->getName() << std::endl;

    ProductA* productA2 = factory2->createProductA();
    std::cout << productA2->getName() << std::endl;

    ProductB* productB2 = factory2->createProductB();
    std::cout << productB2->getName() << std::endl;

    return 0;
}