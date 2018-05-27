from abc import ABC, abstractmethod

class Component(ABC):
    @abstractmethod
    def operation(self):
        pass

class ConcreteComponent(Component):
    def operation(self):
        print("Concrete component op.")

class Decorator(Component):
    def __init__(self, component):
        self._component = component

    @abstractmethod
    def operation(self):
        self._component.operation()

class ConcreteDecoratorA(Decorator):
    def operation(self):
        super().operation()
        print("Concrete decorator A op")

class ConcreteDecoratorB(Decorator):
    def operation(self):
        super().operation()
        print("Concrete decorator B op")

if __name__ == '__main__':
    component = ConcreteComponent()
    component.operation()

    component = ConcreteDecoratorA(component)
    component.operation()

    component = ConcreteDecoratorB(component)
    component.operation()