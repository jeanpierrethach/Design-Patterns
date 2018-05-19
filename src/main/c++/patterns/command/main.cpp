#include <iostream>
#include <vector>
#include <memory>

class Command
{
    public:
        virtual void execute() = 0;
        
};

class Receiver
{
    public:
        void turnOn()
        {
            std::cout<<"The light is on."<<std::endl;
        }

        void turnOff()
        {
            std::cout << "The light is off." << std::endl;
        }

};

class ConcreteCommand1 : public Command
{
    private:
        Receiver* m_receiver;

    public:
        ConcreteCommand1(Receiver* receiver)
            : m_receiver(receiver)
        {
        
        }

        void execute() override
        {
            m_receiver->turnOn();
        }

};

class ConcreteCommand2 : public Command
{
    private:
        Receiver* m_receiver;

    public:
        ConcreteCommand2(Receiver* receiver)
            : m_receiver(receiver)
        {
        
        }

        void execute() override
        {
            m_receiver->turnOff();
        }
};

class Invoker
{
    private:
        std::vector<Command* > m_history_commands;

    public:
        void storeAndExecute(Command* command)
        {
            if (command)
            {
                m_history_commands.push_back(command);
                command->execute();
            }
        }
};

int main()
{
    std::unique_ptr<Receiver> receiver = std::make_unique<Receiver>();
    std::unique_ptr<Command> switchOn(new ConcreteCommand1(receiver.get()));
    std::unique_ptr<Command> switchOff(new ConcreteCommand2(receiver.get()));

    std::unique_ptr<Invoker> switcher = std::make_unique<Invoker>();
    switcher->storeAndExecute(switchOn.get());
    switcher->storeAndExecute(switchOff.get());

    return 0;
}