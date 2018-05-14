#include <iostream>

class State
{
    public:
        virtual ~State()
        {

        }

        virtual void handle() = 0;
};

class ConcreteStateA : public State
{
    public:
        virtual ~ConcreteStateA()
        {

        }

        void handle() override 
        {
            std::cout << "State A handled." << std::endl;
        }
};

class ConcreteStateB : public State
{
    public:
        virtual ~ConcreteStateB()
        {

        }

        void handle() override 
        {
            std::cout << "State B handled." << std::endl;
        }
};

class Context {
    private:
        State* m_state;

    public:
        Context() : m_state() {}
        ~Context()
        {
            delete m_state;
        }

        void setState(State* s)
        {
            if(m_state)
            {
                delete m_state;
            }
            m_state = s;
        }

        void request()
        {
            m_state->handle();
        }
};

int main()
{
    State* stateA = new ConcreteStateA();
    State* stateB = new ConcreteStateB();

    Context* context = new Context();

    context->setState(stateA);
    context->request();

    context->setState(stateB);
    context->request();

    delete context;

    return 0;
}