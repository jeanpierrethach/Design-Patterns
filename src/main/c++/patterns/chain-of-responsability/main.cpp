#include <iostream>
#include <string>

class Handler
{
    protected:
        Handler* m_successor = nullptr;
        float m_balance;

    public:
        Handler(float balance)
            : m_balance(balance)
        {

        }

        void setSuccessor(Handler* handler)
        {
            m_successor = handler;
        }

        bool canHandleRequest(float amount)
        {
            return m_balance >= amount;
        }

        void handleRequest(float amount)
        {
            if (canHandleRequest(amount))
            {
                std::cout << "Paid by " << getClassName() << ". ";
                std::cout << "Old balance: " << m_balance << ". ";
                m_balance -= amount;
                std::cout << "New balance: " << m_balance << std::endl;
            }
            else if (m_successor)
            {
                std::cout << getClassName() << " cannot pay." << std::endl;
                m_successor->handleRequest(amount);
            }
            else
            {
                std::cout << "None could handle the request." << std::endl;
            }
        }

        virtual std::string getClassName() = 0;


};

class Receiver1 : public Handler
{
    public:
        Receiver1(float balance)
            : Handler(balance)
        {
        
        }

    protected:
        std::string getClassName() override
        {
            return "Receiver1";
        }

};

class Receiver2 : public Handler
{
    public:
        Receiver2(float balance)
            : Handler(balance)
        {
        
        }

    protected:
        std::string getClassName() override
        {
            return "Receiver2";
        }
};

class Receiver3 : public Handler
{
    public:
        Receiver3(float balance)
            : Handler(balance)
        {
        
        }

    protected:
        std::string getClassName() override
        {
            return "Receiver3";
        }
};

class Receiver4 : public Handler
{
    public:
        Receiver4(float balance)
            : Handler(balance)
        {
        
        }

    protected:
        std::string getClassName() override
        {
            return "Receiver4";
        }
};

int main()
{
    Receiver1 receiver1(100);
    Receiver2 receiver2(200);
    Receiver3 receiver3(300);
    Receiver4 receiver4(400);

    receiver1.setSuccessor(&receiver2);
    receiver2.setSuccessor(&receiver3);
    receiver3.setSuccessor(&receiver4);

    receiver1.handleRequest(350);

    return 0;
}