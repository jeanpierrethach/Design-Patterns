package facade

class Facade {
    private var subsystemA = new SubsystemA()
    private var subsystemB = new SubsystemB()

    def operation1() {
        subsystemA.operationA1()
        subsystemB.operationB1()
    }

    def operation2() {
        subsystemA.operationA2()
        subsystemB.operationB2()
    }

}

