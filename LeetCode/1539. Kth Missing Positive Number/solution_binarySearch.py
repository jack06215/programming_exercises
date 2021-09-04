def findKthPositive(arr: list, k: int) -> int:
    # keep track of two end points
    left, right = 0, len(arr)
    
    # binary search
    while left < right:
        mid = (left + right) // 2
        # missing number is in the right part
        if arr[mid] - 1 - mid < k:
            left = mid + 1
        
        # or the left part
        else:
            right = mid
    
    return left + k

arr = [1,2,3,4,5]
k = 2
print(findKthPositive(arr, k))