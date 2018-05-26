package factory

class ConcreteProductB1(n: String) extends ProductB(n) {
    def getPrice() : Int = {
        return 200
    }
}