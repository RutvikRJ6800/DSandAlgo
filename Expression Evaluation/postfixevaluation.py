class conversion:
    def __init__(self) -> None:
        self.result = 0
        self.stack = []

    def doOperation(self,c):
        if c == '+':
            a = int(self.stack.pop())
            b = int(self.stack.pop())
            return b + a
        elif c == '-':
            a = int(self.stack.pop())
            b = int(self.stack.pop())
            return b - a
        elif c == '*':
            a = int(self.stack.pop())
            b = int(self.stack.pop())
            return b * a
        elif c == '/':
            a = int(self.stack.pop())
            b = int(self.stack.pop())
            return b // a
        elif c == '^':
            a = int(self.stack.pop())
            b = int(self.stack.pop())
            return b ** a    

    def evaluatePostfix(self,expression):
        for c in expression:
            if c.isalnum():
                self.stack.append(c)

            else:
                temp = self.doOperation(c)
                self.stack.append(temp)

        if len(self.stack) == 1:
            self.result = self.stack[-1]
            return self.result
        else:
            return '$'

if __name__ == '__main__':
    obj = conversion()
    print(obj.evaluatePostfix('234*6*+'))