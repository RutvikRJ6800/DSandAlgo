# creating array and then passing
# def merge(arr,left,right):
#     i = 0
#     j = 0
#     k = 0

#     while i < len(left) and j < len(right):
#         if left[i] < right[j]:
#             arr[k] = left[i]
#             i += 1
#         else:
#             arr[k] = right[j]
#             j += 1
#         k += 1

#     while i < len(left):
#         arr[k] = left[i]
#         i += 1
#         k += 1
        
#     while j < len(right):
#         arr[k] = right[j]
#         j += 1
#         k += 1

# def mergeSort(arr):
#     if len(arr) > 1:
#         mid = len(arr) // 2
#         left = arr[:mid]
#         right = arr[mid:]
#         mergeSort(left)
#         mergeSort(right)
#         merge(arr,left,right)

def printList(arr):
    for i in range(len(arr)):
        print(arr[i], end=" ")
    print()

# if __name__ == '__main__':
#     arr = [6, 5, 12, 10, 9, 1]

#     mergeSort(arr)

#     print("Sorted array is: ")
#     printList(arr)


def merge(arr,p,q,r):
    n1 = q - p + 1
    n2 = r - q

    left = [0]*n1
    right = [0]*n2

    for i in range(0,len(left)):
        left[i] = arr[p+i]

    for i in range(0,len(right)):
        right[i] = arr[q+1+i]

    i = j = 0
    k = p
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1

    while i < len(left):
        arr[k] = left[i]
        i += 1
        k += 1
        
    while j < len(right):
        arr[k] = right[j]
        j += 1
        k += 1

        

def mergeSort(arr,p,r):
    if p < r:
        q = (p+r) // 2
        mergeSort(arr,p,q)
        mergeSort(arr,q+1,r)
        merge(arr,p,q,r)

if __name__ == '__main__':
    arr = [6, 5, 12, 10, 9, 1]

    mergeSort(arr,0,5)

    print("Sorted array is: ")
    printList(arr)


