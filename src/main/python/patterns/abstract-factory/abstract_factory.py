from abc import ABC, abstractmethod

class ProductA(ABC):
    @abstractmethod
    def get_name(self):
        pass

class ConcreteProductA1(ProductA):
    def get_name(self):
        return "A1"

class ConcreteProductA2(ProductA):
    def get_name(self):
        return "A2"

class ProductB(ABC):
    @abstractmethod
    def get_name(self):
        pass

class ConcreteProductB1(ProductB):
    def get_name(self):
        return "B1"

class ConcreteProductB2(ProductB):
    def get_name(self):
        return "B2"

class AbstractFactory(ABC):
    @abstractmethod
    def create_product_a(self):
        pass

    @abstractmethod
    def create_product_b(self):
        pass

class ConcreteFactory1(AbstractFactory):
    def create_product_a(self):
        return ConcreteProductA1()

    def create_product_b(self):
        return ConcreteProductB1()

class ConcreteFactory2(AbstractFactory):
    def create_product_a(self):
        return ConcreteProductA2()

    def create_product_b(self):
        return ConcreteProductB2()

if __name__ == '__main__':
    factory1 = ConcreteFactory1()
    factory2 = ConcreteFactory2()

    product_a1 = factory1.create_product_a()
    print(product_a1.get_name())

    product_b1 = factory1.create_product_b()
    print(product_b1.get_name())

    product_a2 = factory2.create_product_a()
    print(product_a2.get_name())

    product_b2 = factory2.create_product_b()
    print(product_b2.get_name())
    
