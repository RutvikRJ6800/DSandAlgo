# CircularQueue implementation using Array 
class CircularQueue:
    def __init__(self,size):
        self.size = size

        self.data = [None for i in range(size)]
        self.front = -1
        self.rear = -1


    def enqueue(self,item):
        if (self.rear + 1) % self.size == self.front:
            print("Queue is full")
        elif self.front == -1:
            self.front = 0
            self.rear = 0
            self.data[self.rear] = item
        else:
            self.rear = (self.rear + 1) % self.size
            self.data[self.rear] = item

    def dequeue(self):
        if self.front == -1:
            print("Queue is empty")
            return -1
        elif self.rear == self.front:
            temp=self.data[self.front]
            self.front = -1
            self.rear = -1
            return temp                 
        else:
            temp = self.data[self.front]
            self.front = (self.front + 1) % self.size
            print("{} Deleted".format(temp)) 

    def printQueue(self):
        if self.front == -1:
            print("Queue is empty")
        elif (self.rear >= self.front):
            print("Elements in the circular queue are:",end = " ")
            for i in range(self.front, self.rear + 1):
                print(self.data[i], end = " ")
            print ()
        else:
            print ("Elements in Circular Queue are:",end = " ")
            for i in range(self.front, self.size):
                print(self.data[i], end = " ")
            for i in range(0, self.rear + 1):
                print(self.data[i], end = " ")
            print ()
        if ((self.rear + 1) % self.size == self.front):
            print("Queue is Full")

q = CircularQueue(4)   
q.enqueue(1)
q.enqueue(2)
q.printQueue()
# 1 2

q.enqueue(3)
q.printQueue()
# 1 2 3
q.enqueue(4)
q.printQueue()
# full
q.dequeue()
q.dequeue()
q.printQueue()
# 3 4
q.dequeue()
q.dequeue()
q.enqueue(4)
q.printQueue()





