class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right


class BinarySearchTree:
    def __init__(self):
        pass

    def builtBST(self, root, ele):
        if root == None:
            return Node(ele)
        if root.data > ele:
            root.left = self.builtBST(root.left, ele)
        else:
            root.right = self.builtBST(root.right, ele)
        return root

    def preorder(self, root):
        # if root != None:
        #     print(root.data, end=' ')
        #     self.preorder(root.left)
        #     self.preorder(root.right)
        if root is None:
            return
        temp = root
        stack = []
        stack.append(temp)
        while stack:
            current = stack.pop()
            print(current.data, end=' ')
            if current.right:
                stack.append(current.right)
            if current.left:
                stack.append(current.left)
        print()

    def inorder(self,root):
        # if root != None:
        #     self.inorder(root.left)
        #     print(root.data, end=' ')
        #     self.inorder(root.right)
        if root is None:
            return
        current = root
        stack = []
        while True:
            if current is not None:
                stack.append(current)
                current = current.left
            elif stack:
                current = stack.pop()
                print(current.data, end=' ')
                current = current.right
            else:
                break
        print()        

    def postorder(self, root):
        # RECURSIVE CODE
        # if root != None:
        #     self.postorder(root.left)
        #     self.postorder(root.right)
        #     print(root.data, end=' ')
        # ITERATIVE CODE
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
        # result = result.reverse()
        print(result,sep=' ')

    def search(self,root,ele):
        if root == None:
            return False
        elif root.data == ele:
            return True
        else:
            if ele < root.data:
                return self.search(root.left, ele)
            else:
                return self.search(root.right, ele)

    def findMin(self,root):
        # RECURSIVE CODE
        # if root == None:
        #     return
        # elif root.left == None:
        #     return root.data
        # else:
        #     return self.findMin(root.left)
        # ITERATIVE CODE
        temp = root
        while temp.left != None:
            temp = temp.left
        return temp.data

    def findMax(self,root):
        # RECURSIVE CODE
        # if root == None:
        #     return
        # elif root.right == None:
        #     return root.data
        # else:
        #     return self.findMax(root.right)
        # ITERETIVE CODE
        temp = root
        while temp.right != None:
            temp = temp.right
        return temp.data
    
    def inorderPredeccesor(self, root):
        if root is None or root.left is None:
            return
        temp = root.left
        while temp.right:
            temp = temp.right
        return temp.data

    def inorderSuccessor(self,root):
        if root is None or root.right is None:
            temp = root.right
            while temp.left:
                temp = temp.left
            return temp.data




    def delete(self, root, ele):
        if root is None:
            return None
        elif root.data > ele:
            root.left = self.delete(root.left,ele)
        elif root.data < ele:
            root.right = self.delete(root.right,ele)
        else:
            if not (root.left or root.right):
                root = None
            elif root.left:
                root.data = self.inorderPredeccesor(root)
                root.left = self.delete(root.left,ele)
            else:
                root.data = self.inorderSuccessor(root)
                root.right = self.delete(root.right,ele)
        return root

'''
            10
          /
        5          25

    2       7           30
        

'''

if __name__ == '__main__':
    root = None
    b = BinarySearchTree()
    for i in [10, 5, 25, 2, 7, 30]:
        root = b.builtBST(root,i)
    b.inorder(root)
    # search_result = b.search(root, 30)
    # print("Search on 30: Result is -> {}".format('Yes' if search_result==True else 'No'))
    # print("Min element in BST is {}".format(b.findMin(root)))
    # print("Max element in BST is {}".format(b.findMax(root)))
    # b.preorder(root)
    # b.postorder(root)
    # predeccessor = b.inorderPredeccesor(root)
    # print('inorder predeccessor of 10 is {}'.format(predeccessor.data))
    b.delete(root,5)
    b.inorder(root)