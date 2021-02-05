class Solution:          
    def minOperations(self, nums: list, x: int) -> int:
        
        if sum(nums) < x: 
            return -1
        
        result = 10e9
        
        left = len(nums)-1 
        right = len(nums) 
        
        partial_sum = sum(nums)
        while left >= 0:
            if partial_sum >= x:  
                partial_sum -= nums[left]
                left -= 1
            
            if partial_sum < x: 
                right -= 1
                partial_sum += nums[right]
            
            if partial_sum == x: 
                result = min(result, (left + 1) + (len(nums) - right))
                    
        return result if result < 10e9 else -1