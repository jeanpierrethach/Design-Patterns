#include <iostream>

class Visitor;

class Element
{
    public:
        virtual void accept(Visitor & visitor) = 0;
};

class ConcreteElementA;
class ConcreteElementB;

class Visitor
{
    public:
        virtual void visitElementA(ConcreteElementA* element) = 0;
        virtual void visitElementB(ConcreteElementB* element) = 0;
};

class ConcreteVisitor1 : public Visitor
{
    public:
        void visitElementA(ConcreteElementA* ) override
        {
            std::cout << "Concrete visitor 1 visited Element A" << std::endl;
        }

        void visitElementB(ConcreteElementB* ) override
        {
            std::cout << "Concrete visitor 1 visited Element B" << std::endl;
        }
};

class ConcreteVisitor2 : public Visitor
{
    public:
        void visitElementA(ConcreteElementA* ) override
        {
            std::cout << "Concrete visitor 2 visited Element A" << std::endl;
        }

        void visitElementB(ConcreteElementB* ) override
        {
            std::cout << "Concrete visitor 2 visited Element B" << std::endl;
        }
};

class ConcreteElementA : public Element
{
    public:
        void accept(Visitor & visitor) override
        {
            visitor.visitElementA(this);
        }
};

class ConcreteElementB : public Element
{
    public:
        void accept(Visitor & visitor) override
        {
            visitor.visitElementB(this);
        }
};


int main()
{
    ConcreteElementA elementA;
    ConcreteElementB elementB;

    ConcreteVisitor1 visitor1;
    ConcreteVisitor2 visitor2;

    elementA.accept(visitor1);
    elementA.accept(visitor2);

    elementB.accept(visitor1);
    elementB.accept(visitor2);

    return 0;
}