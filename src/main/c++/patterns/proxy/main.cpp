#include <iostream>

class Subject
{
    public:
        virtual ~Subject()
        {

        }

        virtual void operation() = 0;
};

class RealSubject : public Subject
{
    public:
        void operation() override
        {
            std::cout << "Real Subject operation." << std::endl;
        }
};

class Proxy : public Subject
{
    private:
        RealSubject* m_realsubject;

    public:
        Proxy() 
            : m_realsubject(new RealSubject())
        {

        }

        ~Proxy()
        {
            delete m_realsubject;
        }

        void operation() override
        {
            m_realsubject->operation();
        }
};

int main()
{
    Proxy* proxy = new Proxy();
    proxy->operation();

    return 0;
}