def findKthPositive(arr: list, k: int) -> int:
    unseen_val = 0
    pos = 0
    val = 0
    size = len(arr)
    while unseen_val < k:
        val += 1
        if pos < size and arr[pos] == val:
            pos += 1
        else:
            unseen_val += 1
      
    return val


arr = [1,2,3,4,5]
k = 2
print(findKthPositive(arr, k))