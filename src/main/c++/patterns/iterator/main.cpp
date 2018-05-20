#include <iostream>
#include <vector>

class Iterator;

class Aggregate
{
    public:
        virtual Iterator* createIterator() = 0;
};

class ConcreteAggregate : public Aggregate
{
    private:
        std::vector<int> m_vector;

    public:
        ConcreteAggregate(const unsigned int size)
        {
            m_vector.reserve(size);
        }

        unsigned int size() const
        {
            return m_vector.size();
        }

        int at(unsigned int index)
        {
            return m_vector[index];
        }

        void add(int value)
        {
            m_vector.push_back(value);
        }

        Iterator* createIterator() override;
};

class Iterator
{
    public:
        virtual ~Iterator()
        {

        }

        virtual void begin() = 0;
        virtual void next() = 0;
        virtual bool hasNext() = 0;
        virtual int currentItem() = 0;
};

class ConcreteIterator : public Iterator
{
    private:
        ConcreteAggregate* m_aggregate;
        unsigned int m_index;

    public:
        ConcreteIterator(ConcreteAggregate* c_aggregate)
            : m_aggregate(c_aggregate), m_index(0)
        {

        }

        void begin() override
        {
            m_index = 0;
        }

        void next() override
        {
            m_index++;
        }

        bool hasNext() override
        {
            return m_index >= m_aggregate->size();
        }

        int currentItem() override
        {
            return m_aggregate->at(m_index);
        }

};

Iterator* ConcreteAggregate::createIterator()
{
    return new ConcreteIterator(this);
}

int main()
{
    ConcreteAggregate c_aggregate = ConcreteAggregate(5);
    c_aggregate.add(1);
    c_aggregate.add(2);
    c_aggregate.add(3);
    c_aggregate.add(4);
    c_aggregate.add(5);

    Iterator* it = c_aggregate.createIterator();
    for ( ; !it->hasNext(); it->next())
    {
        std::cout << it->currentItem() << std::endl;
    }

    return 0;
}