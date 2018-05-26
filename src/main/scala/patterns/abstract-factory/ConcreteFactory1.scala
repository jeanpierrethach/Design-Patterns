package factory

class ConcreteFactory1 extends AbstractFactory {
    def createProductA(name: String) : ProductA = {
        return new ConcreteProductA1(name)
    }

    def createProductB(name: String) : ProductB = {
        return new ConcreteProductB1(name)
    }
}