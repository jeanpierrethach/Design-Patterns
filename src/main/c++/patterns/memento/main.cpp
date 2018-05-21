#include <iostream>
#include <string>
#include <vector>

class Memento
{
    private:
        std::string m_state;

        friend class Originator;

        Memento(std::string state)
            : m_state(state)
        {

        }

        std::string getState()
        {
            return m_state;
        }
};

class Originator
{
    private:
        std::string m_state;

    public:
        void setState(std::string state)
        {
            m_state = state;
            std::cout << "Set state to " << state << "." << std::endl;
        }

        Memento* createMemento()
        {
            return new Memento(m_state);
        }

        void restore(Memento* memento)
        {
            m_state = memento->getState();
            std::cout << m_state;
        }
};

class Caretaker
{
    private:
        Originator* m_originator;
        std::vector<Memento* > m_history;

    public:
        Caretaker(Originator* originator)
            : m_originator(originator)
        {

        }

        ~Caretaker()
        {
            for (unsigned int i = 0; i < m_history.size(); ++i)
            {
                delete m_history.at(i);
            }
            m_history.clear();
        }

        void save()
        {
            m_history.push_back(m_originator->createMemento());
            std::cout << "Saved state." << std::endl;
        }

        void restore()
        {
            m_originator->restore(m_history.back());
            m_history.pop_back();
            std::cout << " has been restored." << std::endl;
        }
};

int main()
{
    Originator* originator = new Originator();
    Caretaker* caretaker = new Caretaker(originator);

    originator->setState("First state");
    caretaker->save();

    originator->setState("Second state");
    caretaker->save();

    originator->setState("Third state");
    caretaker->restore();

    delete originator;
    delete caretaker;

    return 0;
}