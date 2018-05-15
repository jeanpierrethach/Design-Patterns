#include <iostream>
#include <string>
class Product
{
    private:
        std::string m_partA;
        std::string m_partB;

    public:
        void makeA(const std::string& part)
        {
            m_partA = part;
        }

        void makeB(const std::string& part)
        {
            m_partB = part;
        }

        void print()
        {
            std::cout << m_partA + " " + m_partB << std::endl;
        }
    
};

class Builder
{
    protected:
        Product m_product;

    public:
        virtual ~Builder()
        {

        }

        virtual void buildPartA() = 0;
        virtual void buildPartB() = 0;

        virtual Product getResult() = 0;
};

class ConcreteBuilder : public Builder
{
    public:
        void buildPartA() override
        {
            m_product.makeA("Part A built.");
        }

        void buildPartB() override
        {
            m_product.makeB("Part B built.");
        }

        Product getResult() override
        {
            return m_product;
        }
};

class Director
{
    private:
        Builder* m_builder;

    public:
        Director()
            : m_builder(nullptr)
        {

        }

        ~Director()
        {
            delete m_builder;
        }

        void set(Builder* b)
        {
            m_builder = b;
        }

        void construct()
        {
            m_builder->buildPartA();
            m_builder->buildPartB();
        }
};


int main()
{
    Builder* builder = new ConcreteBuilder();

    Director director;
    director.set(builder);
    director.construct();

    Product product1 = builder->getResult();
    product1.print();

    return 0;
}