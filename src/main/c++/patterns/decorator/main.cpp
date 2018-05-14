#include <iostream>
#include <string>

using std::string;

class Component
{
    public:
        virtual void operation() = 0;
};

class ConcreteComponent : public Component
{
    public:
        void operation() override
        {
            std::cout << "Concrete component op." << std::endl;
        }
};

class Decorator : public Component
{
    protected:
        Component* m_component;
    
    public:
        Decorator(Component* component)
            : m_component(component)
        {

        }

        virtual void operation() override
        {
            m_component->operation();
        }
};

class ConcreteDecoratorA : public Decorator
{
    public:
        ConcreteDecoratorA(Component* component)
            : Decorator(component)
        {

        }

        void operation() override
        {
            std::cout << "Concrete decorator A op." << std::endl;
        }
};

class ConcreteDecoratorB : public Decorator
{
    public:
        ConcreteDecoratorB(Component* component)
            : Decorator(component)
        {

        }

        void operation() override
        {
            std::cout << "Concrete decorator B op." << std::endl;
        }
};

int main()
{
    Component* component = new ConcreteComponent();
    component->operation();

    component = new ConcreteDecoratorA(component);
    component->operation();

    component = new ConcreteDecoratorB(component);
    component->operation();

    return 0;
}