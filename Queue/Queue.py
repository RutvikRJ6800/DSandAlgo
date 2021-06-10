# Queue implementation using Array
class Queue:
    def __init__(self) -> None:
        self.data = []
        self.front = -1
        self.rear = -1

    def enqueue(self,item):
        if self.front == -1:
            self.front = 0
            self.rear = 0
            self.data.insert(self.rear,item)
        else:
            self.rear += 1
            self.data.insert(self.rear,item)
    def dequeue(self):
        if self.front == -1:
            print("Queue is empty") 
        elif self.front == self.rear:
            temp = self.data[self.front]
            self.front = -1
            self.rear = -1
            print("{} deleted".format(temp))
            return temp
        else:
            temp = self.data[self.front]
            self.front += 1
            print("{} deleted".format(temp))
            return temp
    
    def search(self,item):
        if item in self.data:
            print("Item {} Exist".format(item))
        else:
            print("Item {} not Exist".format(item))

    def minimum(self):
        if self.front == -1:
            print("Queue if empty")
            return -1
        min = 99999
        for i in range(self.front,self.rear+1):
            if min > self.data[i]:
                min = self.data[i]
        print("minimum item is {}".format(min))

    def maximum(self):
        if self.front == -1:
            print("Queue if empty")
            return -1
        max = -100000
        for i in range(self.front,self.rear+1):
            if max < self.data[i]:
                max = self.data[i]
        print("maximum item is {}".format(max))


    def printQueue(self):
        if self.front == -1:
            print("Queue is empty")
        else:
            print("Elements in the queue are:",end=" ")
            for i in range(self.front,self.rear+1):
                print(self.data[i],end=" ")
            print()


q = Queue()
q.dequeue() # empty
q.enqueue(1)
q.enqueue(2)
q.printQueue() # 1 2
q.enqueue(3)
q.minimum() # 1
q.maximum() # 3
q.search(4) # No
q.dequeue() # 1 deleted
q.printQueue() # 2 3
q.dequeue() # 2 deleted
q.printQueue() # 3
q.dequeue() # 3 deleted
q.dequeue() # empty
q.maximum()
q.search(4)




