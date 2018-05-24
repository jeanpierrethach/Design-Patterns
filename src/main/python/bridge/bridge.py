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
    def __init__(self, impl):
        self._implementor = impl

    @abstractmethod
    def operation(self):
        pass

class RefinedAbstraction(Abstraction):
    def __init__(self, impl):
        super().__init__(impl)

    def operation(self):
        self._implementor.action()

if __name__ == '__main__':
    abstracts = [
        RefinedAbstraction(ConcreteImplementorA()),
        RefinedAbstraction(ConcreteImplementorB())
    ]

    for abstract in abstracts:
        abstract.operation()