#include <iostream>

class AbstractClass
{
    public:
        virtual ~AbstractClass()
        {

        }

        void templateMethod()
        {
            primitiveOperation1();
            primitiveOperation2();
        };

        virtual void primitiveOperation1() = 0;
        virtual void primitiveOperation2() = 0;
};

class ConcreteClass : public AbstractClass
{
    public:
        void primitiveOperation1() override
        {
            std::cout << "Primitive Operation 1." << std::endl;
        }

        void primitiveOperation2() override
        {
            std::cout << "Primitive Operation 2." << std::endl;
        }
};

int main()
{
    AbstractClass* ac = new ConcreteClass();
    ac->templateMethod();

    return 0;
}