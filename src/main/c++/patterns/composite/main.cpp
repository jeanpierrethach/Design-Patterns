#include <iostream>
#include <vector>
#include <stdexcept>

class Component
{
    public:
        virtual void operation() = 0;
};

class Composite : public Component
{
    private:
        std::vector<Component* > m_childrens;

    public:
        Component* getChild(int index)
        {
           return m_childrens[index]; 
        }

        void add(Component* component)
        {
            m_childrens.push_back(component);
        }

        void remove(int index)
        {
            m_childrens.erase(m_childrens.begin() + index);
        }

        void operation() override
        {
            for (auto child_component : m_childrens)
            {
                child_component->operation();
            }
        }
};

class Leaf : public Component
{
    private:
        int m_id;

    public:
        Leaf(int id)
            : m_id(id)
        {

        }

        void operation() override
        {
            std::cout << "Leaf " << m_id << std::endl; 
        }
};

int main()
{
    Composite composite1; 
    Composite composite2;
    Composite composite3;

    Leaf leaf1(1);
    Leaf leaf2(2);
    Leaf leaf3(3);
    Leaf leaf4(4);

    composite2.add(&leaf1);
    composite2.add(&leaf2);
    composite2.add(&leaf3);

    composite3.add(&leaf4);

    composite1.add(&composite2);
    composite1.add(&composite3);

    composite1.operation();

    return 0;
}
