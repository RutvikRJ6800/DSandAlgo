class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:

    def createBinaryTree(self,root, element):
        if root is None:
            root = Node(element)
            return root
        elif root.data > element:
            root.left = self.createBinaryTree(root.left,element)
        else:
            root.right = self.createBinaryTree(root.right,element)
        return root

    def inorder(self, root):
        if root is None:
            return
        stack = []
        current = root
        while True:
            if current:
                stack.append(current)
                current = current.left
            elif stack:
                current = stack.pop()
                print(current.data, end=' ')
                current = current.right
            else:
                break

    def countNode(self,root):
        if root is None:
            return 0
        return (1 + self.countNode(root.left) + self.countNode(root.right))
    
    def countLeafNode(self, root):
        # RECURSIVE CODE
        # if root is None:
        #     return 0
        # if not (root.left or root.right):
        #     return 1
        # leafAtLeft = self.countLeafNode(root.left)
        # leafAtRight = self.countLeafNode(root.right)
        # return leafAtLeft + leafAtRight
        # ITERATIVE CODE
        if root is None:
            return 0
        temp = root
        stack = []
        count = 0
        stack.append(temp)
        while stack:
            current = stack.pop()
            count += 1
            if current.right:
                stack.append(current.right)
            if current.left:
                stack.append(current.left)
        return count


    def maxDepth(self, root):
        # if root is None:
        #     return 0
        # leftDepth = self.maxDepth(root.left)
        # rightDepth = self.maxDepth(root.right)
        # return 1+max(leftDepth, rightDepth)
        if root is None:
            return 0
        stack = []
        stack.append((1,root))
        depth = 0
        while stack:
            current_depth, current = stack.pop()
            depth = max(depth,current_depth)
            if current.left:
                stack.append((1+current_depth,current.left))
            if current.right:
                stack.append((1+current_depth,current.right))
        return depth




if __name__ == '__main__':
    b = BinaryTree()
    root = None
    elements = [10,7,12,6,9,16,11,19,4,5]
    for ele in elements:
        root = b.createBinaryTree(root, ele)
    b.inorder(root)
    print('No of node in Tree is {}'.format(b.countNode(root)))
    print('No of Leaf node in Tree is {}'.format(b.countLeafNode(root)))
    print('Depth of Tree is {}'.format(b.maxDepth(root)))


            