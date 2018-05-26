package factory

abstract class ProductA(n: String) {
    protected val name = n

    def getName() : String = { return name }
    def getPrice() : Int
}