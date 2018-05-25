from abc import ABC, abstractmethod

class Component(ABC):
    @abstractmethod
    def operation(self):
        pass

class Composite(Component):
    def __init__(self):
        self._childrens = []

    def add(self, component):
        self._childrens.append(component)

    def remove(self, component):
        self._childrens.remove(component)

    def operation(self):
        for children in self._childrens:
            children.operation()

class Leaf(Component):
    def __init__(self, id):
        self._id = id

    def operation(self):
        print("Leaf %d" % self._id)

if __name__ == '__main__':
    composite_1 = Composite()
    composite_2 = Composite()
    composite_3 = Composite()

    leaf_1 = Leaf(1)
    leaf_2 = Leaf(2)
    leaf_3 = Leaf(3)
    leaf_4 = Leaf(4)

    composite_2.add(leaf_1)
    composite_2.add(leaf_2)
    composite_2.add(leaf_3)

    composite_3.add(leaf_4)

    composite_1.add(composite_2)
    composite_1.add(composite_3)

    composite_1.operation()