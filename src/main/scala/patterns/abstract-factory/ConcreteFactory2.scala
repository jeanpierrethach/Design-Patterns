package factory

class ConcreteFactory2 extends AbstractFactory {
    def createProductA(name: String) : ProductA = {
        return new ConcreteProductA2(name)
    }

    def createProductB(name: String) : ProductB = {
        return new ConcreteProductB2(name)
    }
}