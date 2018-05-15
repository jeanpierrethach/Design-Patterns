#include <iostream>

class SubSystemA
{
    public:
        void operationA1()
        {
            std::cout << "Operation A1" << std::endl;
        }

        void operationA2()
        {
            std::cout << "Operation A2" << std::endl;
        }
};

class SubSystemB
{
    public:
        void operationB1()
        {
            std::cout << "Operation B1" << std::endl;
        }

        void operationB2()
        {
            std::cout << "Operation B2" << std::endl;
        }
};

class SubSystemC
{
    public:
        void operationC1()
        {
            std::cout << "Operation C1" << std::endl;
        }

        void operationC2()
        {
            std::cout << "Operation C2" << std::endl;
        }
};

class Facade
{
    private:
        SubSystemA* m_subsystemA;
        SubSystemB* m_subsystemB;
        SubSystemC* m_subsystemC;

    public:
        Facade()
            : m_subsystemA(), m_subsystemB(), m_subsystemC()
        {

        }

        void operation1()
        {
            m_subsystemA->operationA1();
            m_subsystemB->operationB1();
            m_subsystemC->operationC1();
        }

        void operation2()
        {
            m_subsystemA->operationA2();
            m_subsystemB->operationB2();
            m_subsystemC->operationC2();
        }
};

int main()
{
    Facade* facade = new Facade();
    facade->operation1();
    facade->operation2();

    return 0;
}