package factory

class ConcreteProductA1(n: String) extends ProductA(n) {
    def getPrice() : Int = {
        return 100
    }
}