from collections import defaultdict
from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        if len(nums) in [0, 1]:
            return False
        
        freq = defaultdict(int)
        
        for val in nums:
            if freq[val] == 1:
                return True
            freq[val] = freq[val] + 1
        return False