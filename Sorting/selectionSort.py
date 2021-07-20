def selectionSort(arr):
    for i in range(len(arr)):
        min_index = i
        for j in range(i+1,len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

def printList(arr):
    for i in range(0,len(arr)):
        print(arr[i],end=" ")

if __name__ == '__main__':
    li = [6,3,5,8,9,0]
    selectionSort(li)
    printList(li)


