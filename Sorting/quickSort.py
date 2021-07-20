def partition(arr,p,r):
    pivot = arr[r]
    i = p-1
    for j in range(p,r+1):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    i += 1
    arr[i], arr[r] = arr[r], arr[i]
    return i
    
def printList(arr):
    for i in range(0,len(arr)):
        print(arr[i],end=" ")

def quickSort(arr,p,r):
    if p < r:
        q = partition(arr,p,r)
        quickSort(arr,p,q-1)
        quickSort(arr,q+1,r)
if __name__ == '__main__':
    array = [6,3,5,8,9,0]
    quickSort(array,0,len(array)-1)
    printList(array)