from abc import ABC, abstractmethod

class Handler(ABC):
    def __init__(self, balance):
        self._successor = None
        self._balance = balance

    def setSuccessor(self, handler):
        self._successor = handler

    def canHandleRequest(self, amount):
        return self._balance >= amount

    def handleRequest(self, amount):
        if self.canHandleRequest(amount):
            print("Paid by %s" % self.getClassName())
            print("Old balance: %f" % self._balance)
            self._balance -= amount
            print("New balance: %f" % self._balance)
        elif self._successor:
            print(self.getClassName() + " cannot pay")
            self._successor.handleRequest(amount)
        else:
            print("None could handle the request")

    @abstractmethod
    def getClassName(self):
        pass

class Receiver1(Handler):
    def __init__(self, balance):
        super().__init__(balance)

    def getClassName(self):
        return self.__class__.__name__

class Receiver2(Handler):
    def __init__(self, balance):
        super().__init__(balance)

    def getClassName(self):
        return self.__class__.__name__

class Receiver3(Handler):
    def __init__(self, balance):
        super().__init__(balance)

    def getClassName(self):
        return self.__class__.__name__

class Receiver4(Handler):
    def __init__(self, balance):
        super().__init__(balance)

    def getClassName(self):
        return self.__class__.__name__

if __name__ == '__main__':
    receiver1 = Receiver1(100)
    receiver2 = Receiver2(200)
    receiver3 = Receiver3(300)
    receiver4 = Receiver4(400)

    receiver1.setSuccessor(receiver2)
    receiver2.setSuccessor(receiver3)
    receiver3.setSuccessor(receiver4)

    receiver1.handleRequest(350)