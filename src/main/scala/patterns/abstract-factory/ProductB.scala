package factory

abstract class ProductB(n: String) {
    protected val name = n

    def getName() : String = { return name }
    def getPrice() : Int
}