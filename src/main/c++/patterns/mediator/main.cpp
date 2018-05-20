#include <iostream>
#include <string>
#include <vector>

class Mediator;

class Colleague
{
    protected:
        Mediator* m_mediator;
        unsigned int m_id;

    public:

        Colleague(Mediator* m, unsigned int id)
            : m_mediator(m), m_id(id)
        {

        }

        virtual ~Colleague()
        {

        }

        unsigned int getID()
        {
            return m_id;
        }

        virtual void send(std::string) = 0;
        virtual void receive(std::string) = 0;
};

class ConcreteColleague : public Colleague
{
    public:
        ConcreteColleague(Mediator* m, unsigned int id)
            : Colleague(m, id)
        {

        }

        void send(std::string msg) override;
        
        void receive(std::string msg) override
        {
            std::cout << "Message: " << msg << " received by Colleague " << m_id << std::endl;
        }
};

class Mediator
{
    public:
        virtual ~Mediator()
        {

        }

        virtual void add(Colleague* c) = 0;
        virtual void distribute(Colleague* sender, std::string msg) = 0;
};

class ConcreteMediator : public Mediator
{
    private:
        std::vector<Colleague* > m_colleagues;

    public:
        ~ConcreteMediator()
        {
            for (unsigned int i = 0; i < m_colleagues.size(); ++i) {
                delete m_colleagues[i];
            }
            m_colleagues.clear();
        }

        void add(Colleague* c) override
        {
            m_colleagues.push_back(c);
        }

        void distribute(Colleague* sender, std::string msg) override
        {
            for (unsigned int i = 0; i < m_colleagues.size(); ++i)
            {
                if (m_colleagues.at(i)->getID() != sender->getID())
                {
                    m_colleagues.at(i)->receive(msg);
                }
            }
        }

};

void ConcreteColleague::send(std::string msg)
{
    std::cout << "Message: "<< msg << " sent by Colleague " << m_id << std::endl;
    m_mediator->distribute(this, msg);
}

int main()
{
    Mediator* mediator = new ConcreteMediator();

    Colleague* c1 = new ConcreteColleague(mediator, 1);
    Colleague* c2 = new ConcreteColleague(mediator, 2);
    Colleague* c3 = new ConcreteColleague(mediator, 3);

    mediator->add(c1);
    mediator->add(c2);
    mediator->add(c3);

    c1->send("Hi!");
    c3->send("Hello!");

    delete mediator;
    return 0;
}