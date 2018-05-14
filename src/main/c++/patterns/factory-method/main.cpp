#include <iostream>
#include <string>

class Product
{
    public:
        virtual std::string getName() = 0;
};

class ConcreteProductA : public Product
{
    public:
        std::string getName() override
        {
            return "Product A.";
        }
};

class ConcreteProductB : public Product
{
    public:
        std::string getName() override
        {
            return "Product B.";
        }
};

class Creator
{
    public:
        virtual Product* createProductA() = 0;
        virtual Product* createProductB() = 0;
};

class ConcreteCreator : public Creator
{
    public:
        Product* createProductA()
        {
            return new ConcreteProductA();
        }

        Product* createProductB()
        {
            return new ConcreteProductB();
        }
};

int main()
{
    Creator* creator = new ConcreteCreator();

    Product* product1 = creator->createProductA();
    std::cout << product1->getName() << std::endl;

    Product* product2 = creator->createProductB();
    std::cout << product2->getName() << std::endl;

    return 0;
}