class Solution:
    def isValid(self, s: str) -> bool:
        parentheses = {')':'(', 
                       '}':'{', 
                       ']':'['}
        deque = []
        for char in s:
            if deque and (char in parentheses) and (deque[-1] == parentheses[char]):
                deque.pop()
            else:
                deque.append(char)
        return not deque

s = Solution()
print(s.isValid('([)]'))