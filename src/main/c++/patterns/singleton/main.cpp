#include <iostream>

class Singleton
{
    public:
        static Singleton* getInstance()
        {
            if(m_singleton == NULL) 
            {
                m_singleton = new Singleton();
            }

            return m_singleton;
        }

        void print()
        {
            std::cout << "I'm a singleton." << std::endl;
        }
    
    protected:
        Singleton() {};

    private:
        static Singleton* m_singleton;
};

Singleton* Singleton::m_singleton = NULL;

int main()
{
    Singleton* s = Singleton::getInstance();
    s->print();

    return 0;
}