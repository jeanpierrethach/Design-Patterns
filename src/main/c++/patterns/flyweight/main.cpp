#include <iostream>
#include <map>

class Flyweight
{
    public:
        virtual ~Flyweight()
        {

        }
        
        virtual void operation() = 0;
};

class UnsharedConcreteFlyweight : public Flyweight {
    private:
        int m_state;

    public:
        UnsharedConcreteFlyweight(int intrinsic_state)
            : m_state(intrinsic_state) 
        {

        }

        void operation() override
        {
            std::cout << "Unshared Concrete Flyweight state: " << m_state << std::endl;
        }
};

class ConcreteFlyweight : public Flyweight
{
    private:
        int m_state;

    public:
        ConcreteFlyweight(int states)
            : m_state(states)
        {

        }

        void operation() override
        {
            std::cout << "Concrete Flyweight state: " << m_state << std::endl;
        }
};

class FlyweightFactory
{
    private:
        std::map<int, Flyweight* > m_flyweights;

    public:
        virtual ~FlyweightFactory()
        {
            for (auto it = m_flyweights.begin(); it != m_flyweights.end(); ++it)
            {
                delete it->second;
            }
            m_flyweights.clear();
        }

        Flyweight* getFlyweight(int key)
        {
            if (m_flyweights.find(key) != m_flyweights.end())
            {
                return m_flyweights[key];
            }
            Flyweight* flyweight = new ConcreteFlyweight(key);
            m_flyweights.insert(std::pair<int, Flyweight* >(key, flyweight));
            return flyweight;
        }
};

int main()
{
    FlyweightFactory* factory = new FlyweightFactory();
    factory->getFlyweight(1)->operation();
    factory->getFlyweight(2)->operation();

    return 0;
}