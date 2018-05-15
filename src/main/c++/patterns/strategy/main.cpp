#include <iostream>

class Strategy
{
    public:
        virtual ~Strategy()
        {

        }

        virtual void algorithm() = 0;
};

class ConcreteStrategyA : public Strategy
{
    void algorithm()
    {
        std::cout << "Concrete Strategy A" << std::endl;
    }
};

class ConcreteStrategyB : public Strategy
{
    void algorithm()
    {
        std::cout << "Concrete Strategy B" << std::endl;
    }
};

class ConcreteStrategyC : public Strategy
{
    void algorithm()
    {
        std::cout << "Concrete Strategy C" << std::endl;
    }
};

class Context
{
    private:
        Strategy* m_strategy;

    public:
        Context(Strategy* strat)
            : m_strategy(strat)
        {

        }

        void operation()
        {
            m_strategy->algorithm();
        }

        void setStrategy(Strategy* strat)
        {
            m_strategy = strat;
        }
};

int main()
{
    ConcreteStrategyA strategyA;
    ConcreteStrategyB strategyB;
    ConcreteStrategyC strategyC;

    Context context(&strategyA);
    context.operation();

    context.setStrategy(&strategyB);
    context.operation();

    context.setStrategy(&strategyC);
    context.operation();

    return 0;
}