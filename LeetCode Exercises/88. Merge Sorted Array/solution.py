def merge(nums1: list, m: int, nums2: list, n: int) -> None:
    """
    Do not return anything, modify nums1 in-place instead.
    """
    start = m
    while start < len(nums1):
        if nums1[start] == 0: break
        start += 1
    
    nums1[start:] = nums2[:]
    nums1[:] = sorted(nums1[:])


def merge_shorter(nums1: list, m: int, nums2: list, n: int) -> None:
    nums1[m:] = nums2[:n]
    nums1.sort()

l1 = [1,2,3,0,0,0]
m = 3
l2 = [2,5,6]
n = 3
merge_shorter(l1,m,l2,n)
print(l1)