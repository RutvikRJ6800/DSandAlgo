# Implementation of priority queue using Heap data structure,
class priorityQueue:
    def __init__(self,data = []):
        self.data = data

    def createPrioriryQueue(self, arr):
        n = len(arr)
        for i in range(n//2,-1,-1):
            self.heapify(arr,n,i)
        self.data = arr

    def heapify(self, arr, n, i):
        leftChild = 2*i + 1
        rightChild = 2*i + 2
        largest = i
        if leftChild < n and arr[leftChild] > arr[i]:
            largest = leftChild
        if rightChild < n and arr[rightChild] > arr[largest]:
            largest = rightChild
        if largest != i:
            arr[i], arr[largest] = arr[largest], arr[i]
            self.heapify(arr,n,largest)

    def maximum(self):
        if len(self.data) == 0:
            return -1 #element yet to be added
        return self.data[0]

    def extractMax(self):
        n = len(self.data)
        if n == 0:
            return -1
        self.data[0], self.data[n-1] = self.data[n-1], self.data[0]
        returnResult = self.data.pop()
        self.heapify(self.data,len(self.data),0)
        return returnResult

    def increaseKey(self,old,new):
        if old > new or len(self.data) == 0:
            return -1
        index = self.data.index(old)
        self.data[index] = new
        while index != 0:
            self.heapify(self.data, len(self.data), index)
            index = (index-1)//2
        self.heapify(self.data, len(self.data), index)
    
    def insert(self, val):
        self.data.append(val)
        index = len(self.data)-1
        while index != 0:
            self.heapify(self.data, len(self.data), index)
            index = (index-1)//2
        self.heapify(self.data, len(self.data), index)

    def printQueue(self): # This is just to see elements inside Queue
        print(self.data)        


if __name__ == '__main__':
    p = priorityQueue()
    p.createPrioriryQueue([4,1,3,2,16,9,10,14,8,7])
    p.printQueue()
    # print(p.maximum())
    # print(p.extractMax())
    # p.printQueue()
    # print(p.extractMax())
    # p.printQueue()
    p.increaseKey(9,12)
    p.printQueue()
    p.insert(50)
    p.printQueue()
