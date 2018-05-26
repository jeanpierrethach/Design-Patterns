package factory

class ConcreteProductA2(n: String) extends ProductA(n) {
    def getPrice() : Int = {
        return 150
    }
}