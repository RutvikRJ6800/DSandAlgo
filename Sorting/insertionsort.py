def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < li[j]:
            li[j+1] = li[j]
            j -= 1
        li[j+1] = key

def printList(arr):
    for i in range(0,len(arr)):
        print(arr[i],end=" ")


li = [6,3,5,8,9,0]
insertionSort(li)
printList(li)


