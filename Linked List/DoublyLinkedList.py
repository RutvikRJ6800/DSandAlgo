class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
        self.prev = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def createLinkedList(self):
        arr = [int(item) for item in input().split()]
        for item in arr:
            newNode = Node(item) 
            if self.head == None and self.tail == None:
                self.head = newNode
                self.tail = newNode
            else:
                self.tail.next = newNode
                newNode.prev =self.tail
                self.tail = newNode

    def printLinkedList(self):
        temp = self.head
        while temp:
            print("{} ->".format(temp.data),end=" ")
            temp = temp.next
        print('None')
        print()

    def delete(self,item):
        pointer = self.search(item) 
        if pointer == None:
            print("1 exe")
            print("Item is not present")
            return -1
        elif pointer.next == None:
            if self.head == pointer:
                print("2A exe")
                self.head = None
                self.tail = None
                print("{} deleted".format(item))
                return item
            else:
                print("2B exe")
                pointer.prev.next = None
                self.tail = pointer.prev
                print("{} deleted".format(item))
                return item
        elif pointer.prev == None:
            print("3 exe")
            self.head = pointer.next
            self.head.prev = None
            print("{} deleted".format(item))
            return item
        else:
            print("4 exe")
            pointer.prev.next = pointer.next
            pointer.next.prev = pointer.prev
            print("{} deleted".format(item))
            return item

    def insertAtEnd(self,item):
        newNode = Node(item)
        self.tail.next = newNode
        newNode.prev = self.tail
        self.tail = newNode

    def insertAtStart(self,item):
        newNode = Node(item)
        newNode.next = self.head
        self.head.prev = newNode
        self.head = newNode
    
    def insertAtMiddleBefore(self,data,before):
        newNode = Node(data)
        if self.head.data == before:
            self.insertAtStart(data)
        else:
            temp = self.head
            while temp.next.data != before:
                temp = temp.next
            newNode.next = temp.next
            temp.next = newNode

    def insertAtMiddleAfter(self,data,after):
        newNode = Node(data)
        if self.tail.data == after:
            self.tail = newNode
        temp = self.head
        while temp.data != after:
            temp = temp.next
        newNode.next = temp.next
        temp.next = newNode

    def search(self,item):
        temp = self.head
        while temp:
            if temp.data == item:
                print("{} exist".format(item))
                return temp
            temp = temp.next
        print("Item does not exist")
        return None

    def minimum(self):
        min = 99999
        temp = self.head
        while temp:
            if min > temp.data:
                min = temp.data
                temp = temp.next
            else:
                temp = temp.next
        print("minimum element in Linked List is {}".format(min))
        return min

    def maximum(self):
        max = -100000
        temp = self.head
        while temp:
            if max < temp.data:
                max = temp.data
                temp = temp.next
            else:
                temp = temp.next
        print("maximum element in Linked List is {}".format(max))
        return max

    def predecessor(self,item):
        temp = self.head
        if temp.data == item:
            print("First element does not have predecessor")
            return -1
        while temp.next.data != item:
            temp = temp.next
        predecessor = temp.data
        print("predecessor of {} is {}".format(item,predecessor))
        return predecessor

    def successor(self,item):
        temp = self.head
        while temp.data != item:
            temp = temp.next

        if temp.next == None:
            print("Last Element does not have successor")
            return -1
        successor = temp.next.data
        print("successor of {} is {}".format(item,successor))
        return successor

l1 = LinkedList()
l1.createLinkedList()
l1.printLinkedList()
l1.insertAtEnd(5)
l1.printLinkedList()
l1.insertAtStart(0)
l1.printLinkedList()
# 
l1.insertAtMiddleBefore(9,3)
l1.printLinkedList()
# 
l1.insertAtMiddleAfter(6,5)
l1.printLinkedList()
l1.search(8)
l1.maximum()
l1.minimum()
# 
l1.predecessor(1)
l1.predecessor(0)
l1.successor(5)
l1.successor(6)
l1.insertAtMiddleAfter(7,6)
l1.printLinkedList()
l1.insertAtMiddleBefore(10,0)
l1.printLinkedList()
l1.delete(0)
l1.printLinkedList()
l1.delete(10)
l1.printLinkedList()
l1.delete(6)
l1.printLinkedList()
l1.delete(7)
l1.printLinkedList()
l1.insertAtEnd(10)
l1.printLinkedList()
l1.insertAtStart(0)
l1.printLinkedList()


