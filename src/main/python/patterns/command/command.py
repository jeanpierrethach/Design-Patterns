from collections import deque
from abc import ABC, abstractmethod

class Command(ABC):
    def __init__(self, receiver):
        self._receiver = receiver

    @abstractmethod
    def execute(self):
        pass

class Receiver(object):
    def turn_on(self):
        print("The light is on")
    
    def turn_off(self):
        print("The light is off")

class ConcreteCommand1(Command):
    def execute(self):
        self._receiver.turn_on()
        
class ConcreteCommand2(Command):
    def execute(self):
        self._receiver.turn_off()

class Invoker(object):
    def __init__(self):
        self._history = deque()

    def store_and_execute(self, command):
        self._history.append(command)
        command.execute()

    def history(self):
        return self._history

class Client(object):
    def __init__(self):
        self._lamp = Receiver()
        self._invoker = Invoker()
    
    def action(self, command):
        cmd = command.strip().upper()
        if cmd == "ON":
            self._invoker.store_and_execute(ConcreteCommand1(self._lamp))
        elif cmd == "OFF":
            self._invoker.store_and_execute(ConcreteCommand2(self._lamp))
        else:
            print("This command doesn't exist. Only 'ON' and 'OFF' are allowed.")

    def get_invoker(self):
        return self._invoker

if __name__ == '__main__':
    client = Client()
    client.action("ON")
    client.action("OFF")
    client.action("Close")
    
    print(client.get_invoker().history())