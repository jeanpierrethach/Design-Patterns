from abc import ABC, abstractmethod

class Product(object):
    def __init__(self):
        self._part_a = None
        self._part_b = None

    def make_a(self, part):
        self._part_a = part

    def make_b(self, part):
        self._part_b = part

    def __str__(self):
        return "%s %s" % (self._part_a, self._part_b)

class Builder(ABC):
    @abstractmethod
    def build_part_a(self):
        pass

    @abstractmethod
    def build_part_b(self):
        pass

    @abstractmethod
    def get_result(self):
        pass

class ConcreteBuilder(Builder):
    def __init__(self):
        self._product = Product()
    
    def build_part_a(self):
        self._product.make_a("Part A built.")

    def build_part_b(self):
        self._product.make_b("Part B built.")

    def get_result(self):
        return self._product

class Director(object):
    def __init__(self, builder):
        self._builder = builder

    def set(self, builder):
        self._builder = builder

    def construct(self):
        self._builder.build_part_a()
        self._builder.build_part_b()

if __name__ == '__main__':
    builder = ConcreteBuilder()

    director = Director(builder)
    director.construct()

    product1 = builder.get_result()
    print(product1)