from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        if len(nums) in [0, 1]:
            return False
        
        nums = sorted(nums)
        for i in range(len(nums) - 1):
            if nums[i] == nums[i + 1]:
                return True
        return False