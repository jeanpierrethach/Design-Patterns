from abc import ABC, abstractmethod

class Implementor(ABC):
    @abstractmethod
    def action(self):
        pass

class ConcreteImplementorA(Implementor):
    def action(self):
        print("Concrete Implementor A.")

class ConcreteImplementorB(Implementor):
    def action(self):
        print("Concrete Implementor B.")

class Abstraction(ABC):
    @abstractmethod
    def operation(self):
        pass

class RefinedAbstraction(Abstraction):
    def __init__(self, impl):
        self._implementor = impl

    def operation(self):
        self._implementor.action()

if __name__ == '__main__':
    implementorA = ConcreteImplementorA()
    implementorB = ConcreteImplementorB()

    abstractA = RefinedAbstraction(implementorA)
    abstractA.operation()

    abstractB = RefinedAbstraction(implementorB)
    abstractB.operation()