from abc import ABC, abstractmethod

class Product(object):
    def __init__(self):
        self._partA = None
        self._partB = None

    def makeA(self, part):
        self._partA = part

    def makeB(self, part):
        self._partB = part

    def __str__(self):
        return "%s %s" % (self._partA, self._partB)

class Builder(ABC):
    @abstractmethod
    def buildPartA(self):
        pass

    @abstractmethod
    def buildPartB(self):
        pass

    @abstractmethod
    def getResult(self):
        pass

class ConcreteBuilder(Builder):
    def __init__(self):
        self._product = Product()
    
    def buildPartA(self):
        self._product.makeA("Part A built.")

    def buildPartB(self):
        self._product.makeB("Part B built.")

    def getResult(self):
        return self._product

class Director(object):
    def __init__(self, builder):
        self._builder = builder

    def set(self, builder):
        self._builder = builder

    def construct(self):
        self._builder.buildPartA()
        self._builder.buildPartB()

if __name__ == '__main__':
    builder = ConcreteBuilder()

    director = Director(builder)
    director.construct()

    product1 = builder.getResult()
    print(product1)