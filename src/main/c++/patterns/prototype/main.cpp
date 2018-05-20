#include <iostream>
#include <string>
#include <memory>
#include <map>

class Prototype
{
    public:
        virtual std::unique_ptr<Prototype> clone() = 0;
        virtual void print() = 0;
};

class ConcretePrototype1 : public Prototype
{
    public:
        std::unique_ptr<Prototype> clone() override
        {
            return std::unique_ptr<Prototype>(new ConcretePrototype1());
        }

        void print() override
        {
            std::cout << "Concrete Prototype 1" << std::endl;
        }
};

class ConcretePrototype2 : public Prototype
{
    public:
        std::unique_ptr<Prototype> clone() override
        {
            return std::unique_ptr<Prototype>(new ConcretePrototype2());
        }

        void print() override
        {
            std::cout << "Concrete Prototype 2" << std::endl;
        }
};

class PrototypeFactory 
{
    private:
        std::map<int, std::unique_ptr<Prototype>> m_prototypes;

    public:
        enum Type {
            PROTOTYPE1,
            PROTOTYPE2
        };

        PrototypeFactory()
        {
            m_prototypes[PROTOTYPE1] = std::unique_ptr<ConcretePrototype1>(new ConcretePrototype1());
            m_prototypes[PROTOTYPE2] = std::unique_ptr<ConcretePrototype2>(new ConcretePrototype2());
        }

        std::unique_ptr<Prototype> clone(Type type)
        {
            return m_prototypes[type]->clone();
        }
};

int main()
{
    PrototypeFactory proto_factory;
    auto cloned_p1 = proto_factory.clone(proto_factory.PROTOTYPE1);
    cloned_p1->print();

    auto cloned_p2 = proto_factory.clone(proto_factory.PROTOTYPE2);
    cloned_p2->print();

    return 0;
}