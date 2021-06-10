#  Using POP method(inbuilt)
# class Stack:
#     def __init__(self):
#         self.__data = []

#     def push(self,item):
#         self.__data.append(item)

#     def pop(self):
#         if self.isEmpty():
#             print("Underflow")
#             return
#         self.__data.pop()

#     def isEmpty(self):
#         if len(self.__data) == 0:
#             return True
#         else:
#             return False


#  This Implementation Conatain Top(Stack Pointer)

class Stack:
    def __init__(self):
        self.data = []
        self.top = -1

    def push(self,item):
        self.top += 1
        print(self.top)
        self.data.insert(self.top,item)

    def pop(self):
        if self.top == -1:
            print("Underflow")
        returnItem = self.data[self.top]
        self.top -= 1
        return returnItem

    def search(self,item):
        if item in self.data:
            print("Item {} Exist".format(item))
        else:
            print("Item {} not Exist".format(item))

    def printStack(self):
        print(self.data)

    def minimum(self):
        min = 99999
        for i in range(0,len(self.data)):
            if min > self.data[i]:
                min = self.data[i]
        print("minimum item is {}".format(min))

    def maximum(self):
        max = -100000
        for i in range(0,len(self.data)):
            if max < self.data[i]:
                max = self.data[i]
        print("maximum item is {}".format(max))

    def successor(self,item):
        if self.data[self.top] == item:
            print("Successor of {} is not present".format(item))
        else:
            inx = self.data.index(item)
            print("Succesor of {} is {}".format(item,self.data[inx+1]))

    def predecessor(self,item):
        inx = self.data.index(item)
        if inx == 0:
            print("Predecessor of {} is not present".format(item))
        else:
            print("Predecessor of {} is {}".format(item,self.data[inx-1]))


s = Stack()
s.push(1)
s.push(2)
s.printStack()
s.push(3)
s.printStack()
s.search(1)
s.minimum()
s.maximum()
s.predecessor(2)
s.successor(2)
s.predecessor(1)
s.successor(3)
