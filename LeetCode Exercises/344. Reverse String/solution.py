from typing import List

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        def swap(left, right, s):
            if left >= right:
                return None
            s[left], s[right] = s[right], s[left]
            swap(left + 1, right - 1, s)
        
        swap(0, len(s) - 1, s)
        print(s)
    

input_seq = ["h","e","l","l","o"]
s = Solution()
s.reverseString(input_seq)
        