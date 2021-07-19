# This algorithm perform minimum swap to sort array. 
def bubblesort(arr):
    flag = True
    for i in range(0,len(arr)-1):
        if flag != False:
            flag = False
            for j in range(0,len(arr)-(i+1)):
                if arr[j] > arr[j+1]:
                    temp = arr[j]
                    arr[j] = arr[j+1]
                    arr[j+1] = temp
                    flag = True
        else:
            break


def printList(arr):
    for i in range(len(arr)):
        print(arr[i], end=" ")
    print()

if __name__ == '__main__':
    arr = [6, 5, 12, 10, 9, 1]

    bubblesort(arr)

    print("Sorted array is: ")
    printList(arr)
