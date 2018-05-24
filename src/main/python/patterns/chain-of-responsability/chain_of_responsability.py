from abc import ABC, abstractmethod

class Handler(ABC):
    def __init__(self, balance):
        self._successor = None
        self._balance = balance

    def set_successor(self, handler):
        self._successor = handler

    def can_handle_request(self, amount):
        return self._balance >= amount

    def handle_request(self, amount):
        if self.can_handle_request(amount):
            print("Paid by %s" % self.get_name())
            print("Old balance: %f" % self._balance)
            self._balance -= amount
            print("New balance: %f" % self._balance)
        elif self._successor:
            print(self.get_name() + " cannot pay")
            self._successor.handle_request(amount)
        else:
            print("None could handle the request")

    @abstractmethod
    def get_name(self):
        pass

class Receiver1(Handler):
    def get_name(self):
        return "Receiver 1"

class Receiver2(Handler):
    def get_name(self):
        return "Receiver 2"

class Receiver3(Handler):
    def get_name(self):
        return "Receiver 3"

class Receiver4(Handler):
    def get_name(self):
        return "Receiver 4"

if __name__ == '__main__':
    receiver1 = Receiver1(100)
    receiver2 = Receiver2(200)
    receiver3 = Receiver3(300)
    receiver4 = Receiver4(400)

    receiver1.set_successor(receiver2)
    receiver2.set_successor(receiver3)
    receiver3.set_successor(receiver4)

    receiver1.handle_request(350)