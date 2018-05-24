from abc import ABC, abstractmethod

class ProductA(ABC):
    @abstractmethod
    def getName(self):
        pass

class ConcreteProductA1(ProductA):
    def getName(self):
        return "A1"

class ConcreteProductA2(ProductA):
    def getName(self):
        return "A2"

class ProductB(ABC):
    @abstractmethod
    def getName(self):
        pass

class ConcreteProductB1(ProductB):
    def getName(self):
        return "B1"

class ConcreteProductB2(ProductB):
    def getName(self):
        return "B2"

class AbstractFactory(ABC):
    @abstractmethod
    def createProductA(self):
        pass

    @abstractmethod
    def createProductB(self):
        pass

class ConcreteFactory1(AbstractFactory):
    def createProductA(self):
        return ConcreteProductA1()

    def createProductB(self):
        return ConcreteProductB1()

class ConcreteFactory2(AbstractFactory):
    def createProductA(self):
        return ConcreteProductA2()

    def createProductB(self):
        return ConcreteProductB2()

if __name__ == '__main__':
    factory1 = ConcreteFactory1()
    factory2 = ConcreteFactory2()

    productA1 = factory1.createProductA()
    print(productA1.getName())

    productB1 = factory1.createProductB()
    print(productB1.getName())

    productA2 = factory2.createProductA()
    print(productA2.getName())

    productB2 = factory2.createProductB()
    print(productB2.getName())
    
