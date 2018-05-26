import factory._

object Main {
    def main(args: Array[String]) {
        val factory1 = new ConcreteFactory1
        val factory2 = new ConcreteFactory2

        val productA1 = factory1.createProductA("A1")
        println(productA1.getPrice())

        val productB1 = factory1.createProductB("B1")
        println(productB1.getPrice())

        val productA2 = factory2.createProductA("A2")
        println(productA2.getPrice())

        val productB2 = factory2.createProductB("B2")
        println(productB2.getPrice())
    }
}