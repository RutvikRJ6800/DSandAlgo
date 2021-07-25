def countingSort(arr):
    max_ele = max(arr)
    n = len(arr)
    B = [0]*n   # this is auxilary array to store the result
    C = [0]*(max_ele+1)  # this array will count the occurance of elements

    for i in range(n):
        C[arr[i]] += 1

    for i in range(1,max_ele+1):    #This loop will calculate cummulative sum
        C[i] = C[i] + C[i-1]

    for j in range(n-1,-1,-1):  #Using C we will store result in B
        B[C[arr[j]]-1] = arr[j]
        C[arr[j]] -= 1

    for j in range(n):  #Copy B into arr
        arr[j] = B[j]

def printList(arr):
    for i in range(0, len(arr)):
        print(arr[i], end=" ")


if __name__ == '__main__':
    li = [7,2,9,1,5,7,4]
    countingSort(li)
    printList(li)
