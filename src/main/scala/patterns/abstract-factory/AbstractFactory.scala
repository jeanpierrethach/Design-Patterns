package factory

abstract class AbstractFactory {
    def createProductA(name: String) : ProductA
    def createProductB(name: String) : ProductB
}