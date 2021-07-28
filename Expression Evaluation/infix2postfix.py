class conversion:
    def __init__(self):
        self.stack = []
        self.result = []
        self.precedence = {'(':0, '+':1, '-':1, '*':2, '/':2, '^':3}

    def isempty(self):
        return True if len(self.stack) == 0 else False

    def notgreater(self,c):
        a = self.precedence[self.peek()]
        b = self.precedence[c]
        return True if a >= b else False
        
    def peek(self):
        if len(self.stack) > 0 :
            return self.stack[-1]
        else:
            return '$'


    def infixtopostfix(self,expression):
        
        for c in expression:
            if c.isalnum():
                self.result.append(c)

            elif c == '(':
                self.stack.append('(') 

            elif c == ')':
                temp = self.stack.pop()
                while temp != '(':
                    self.result.append(temp)
                    temp = self.stack.pop()
            
            else:
                while (not self.isempty() and self.notgreater(c)):
                    self.result.append(self.stack.pop())
                self.stack.append(c)
        return "" .join(self.result)

if __name__ == '__main__':
    obj = conversion()
    result = obj.infixtopostfix('(2*3+4*(5-6))')
    print(result)