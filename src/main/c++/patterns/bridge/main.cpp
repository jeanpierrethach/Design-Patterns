#include <iostream>

class Implementor
{
    public:
        virtual void action() = 0;
};

class ConcreteImplementorA : public Implementor
{
    public:
        void action() override
        {
            std::cout << "Concrete Implementor A." << std::endl;
        }
};

class ConcreteImplementorB : public Implementor
{
    public:
        void action() override
        {
            std::cout << "Concrete Implementor B." << std::endl;
        }
};

class Abstraction
{
    public:
        virtual void operation() = 0;
};

class RefinedAbstraction : public Abstraction
{
    private:
        Implementor* m_implementor;

    public:
        RefinedAbstraction(Implementor* impl)
            : m_implementor(impl)
        {

        }

        void operation() override
        {
            m_implementor->action();
        }

};

int main()
{
    Implementor* implementorA = new ConcreteImplementorA();
    Implementor* implementorB = new ConcreteImplementorB();
    
    Abstraction* abstractA = new RefinedAbstraction(implementorA);
    abstractA->operation();

    Abstraction* abstractB = new RefinedAbstraction(implementorB);
    abstractB->operation();

    return 0;
}