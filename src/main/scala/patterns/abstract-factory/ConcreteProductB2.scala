package factory

class ConcreteProductB2(n: String) extends ProductB(n) {
    def getPrice() : Int = {
        return 250
    }
}