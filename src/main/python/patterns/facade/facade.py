class SubsystemA(object):
    def operation_a1(self):
        print("Operation a1")

    def operation_a2(self):
        print("Operation a2")

class SubsystemB(object):
    def operation_b1(self):
        print("Operation b1")

    def operation_b2(self):
        print("Operation b2")

class SubsystemC(object):
    def operation_c1(self):
        print("Operation c1")

    def operation_c2(self):
        print("Operation c2")

class Facade(object):
    def __init__(self):
        self.subsystem_a = SubsystemA()
        self.subsystem_b = SubsystemB()
        self.subsystem_c = SubsystemC()
    
    def operation1(self):
        self.subsystem_a.operation_a1()
        self.subsystem_b.operation_b1()
        self.subsystem_c.operation_c1()

    def operation2(self):
        self.subsystem_a.operation_a2()
        self.subsystem_b.operation_b2()
        self.subsystem_c.operation_c2()

if __name__ == '__main__':
    facade = Facade()
    facade.operation1()
    facade.operation2()