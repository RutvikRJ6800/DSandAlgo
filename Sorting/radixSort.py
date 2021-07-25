def countingSort(arr,place):
    n = len(arr)
    B = [0]*n
    C = [0]*10

    for i in range(n):
        index = arr[i] // place
        C[index % 10] += 1

    for i in range(1,10):
        C[i] = C[i] + C[i-1]

    for i in range(n-1,-1,-1):
        index = arr[i] // place
        B[C[index%10]-1] = arr[i]
        C[index%10] -= 1

    for i in range(n): 
        arr[i] = B[i]

def radixSort(arr):
    max_ele = max(arr)
    place = 1

    while max_ele // place > 0:
        countingSort(arr,place)
        place = place*10

if __name__ == '__main__':
    arr = [121, 432, 564, 23, 1, 788]
    radixSort(arr)
    print(arr)