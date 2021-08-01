class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

class ExpressionTree:

    def postfixToExpresssionTree(self,expression):
        stack = []
        for ele in expression:
            if ele.isnumeric():
                stack.append(Node(int(ele)))
            else:
                right = stack.pop()
                left = stack.pop()
                stack.append(Node(ele,left,right))
        return stack.pop()
                
    def postorder(self,root):
        if root == None:
            return
        temp = root
        stack = []
        result = []
        stack.append(temp)
        while stack:
            current = stack.pop()
            result.append(current.data)
            if current.left:
                stack.append(current.left)
            if current.right:
                stack.append(current.right)

        result.reverse()
        return result
    
    def evaluateBinaryOperation(self,op,a,b):
        if op == '+':
            return a + b
        elif op == '-':
            return a - b
        elif op == '*':
            return a * b
        elif op == '/':
            return a // b
        elif op == '^':
            return a ** b
        else:
            return '$'

    
    def evaluateExpressionTree(self,root):
        if root is None:
            return 
        if isinstance(root.data,int):
            return root.data
        else:
            lEvaluation = self.evaluateExpressionTree(root.left)
            rEvaluation = self.evaluateExpressionTree(root.right)

            return self.evaluateBinaryOperation(root.data,lEvaluation,rEvaluation)



if __name__ == '__main__':
    root = None
    expression = '23+456+**'
    e = ExpressionTree()
    root = e.postfixToExpresssionTree(expression)
    print(e.postorder(root))
    print("Answer is {}".format(e.evaluateExpressionTree(root)))