

def backtracking(n, nums):
    print(nums)
    if n >= 2:
        return
    for i in range(1, 3):
        new_nums = nums + [i]
        backtracking(n+1, new_nums)
        
        
backtracking(0, [])
