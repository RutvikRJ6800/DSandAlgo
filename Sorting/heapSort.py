class Heap:
    def heapify(self, arr, n, i):
        largest = i
        leftChild = 2*i + 1
        rightChild = 2*i + 2
        if leftChild < n and arr[leftChild] > arr[i]:
            largest = leftChild
        if rightChild < n and arr[rightChild] > arr[largest]:
            largest = rightChild
        if largest != i:
            arr[largest], arr[i] = arr[i], arr[largest]
            self.heapify(arr,n,largest)
    
    def buildHeap(self, arr, n):
        for i in range(n//2,-1,-1):
            self.heapify(arr,n,i)
        print(arr)
    
    def heapSort(self, arr):
        n = len(arr)
        self.buildHeap(arr,n)
        for i in range(n-1,0,-1):
            arr[0], arr[i] = arr[i], arr[0]
            self.heapify(arr,i,0)

if __name__ == '__main__':
    h = Heap()
    arr = [4,1,3,2,16,9,10,14,8,7]
    # h.buildHeap(arr, len(arr))
    print(arr)
    h.heapSort(arr)
    print(arr)

        