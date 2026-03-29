# варіант 4  Лабораторна №4

class Node:
    def __init__(self, cargo=None, next=None):
        self.cargo = cargo
        self.next = next

    def __str__(self):
        return str(self.cargo)


class LinkedList:
    def __init__(self):
        self.length = 0
        self.head = None
        self.tail = None

    def addFirst(self, e):
        node = Node(e)
        if self.length == 0:
            self.head = node
            self.tail = node
        else:
            node.next = self.head
            self.head = node
        self.length += 1

    def takeLast(self):
        if self.length == 0:
            raise IndexError("Порожній список")

        if self.head == self.tail:
            value = self.head.cargo
            self.head = self.tail = None
            self.length -= 1
            return value
        else:
            current = self.head
            while current.next != self.tail:
                current = current.next

            value = self.tail.cargo
            self.tail = current
            self.tail.next = None
            self.length -= 1
            return value

    def __str__(self):
        node = self.head
        string = ''
        while node:
            string += str(node) + ' '
            node = node.next
        return string.strip()


class Queue:
    def __init__(self):
        self.list = LinkedList()

    def enqueue(self, e):
        self.list.addFirst(e)

    def dequeue(self):
        return self.list.takeLast()

    def size(self):
        return self.list.length

    def clear(self):
        self.list.head = None
        self.list.tail = None
        self.list.length = 0

    def __str__(self):
        return str(self.list)


queue = Queue()
queue.enqueue(1)
queue.enqueue(2)
queue.enqueue(3)
queue.enqueue(2)
queue.enqueue(3)

print(queue)
print(queue.dequeue())
print(queue)
print(queue.size())
# queue.clear()