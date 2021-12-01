class Solution:
    def __init__(self):
        self.ans = []

    def helper(self, colorRemain, ballRemain, comb):
        # 只剩下一種顏色，拿全部剩下的球數補足
        if colorRemain == 1:
            self.ans.append(comb[:] + [ballRemain])
            return

        for n in range(ballRemain + 1):
            comb.append(n)
            self.helper(colorRemain - 1, ballRemain - n, comb)
            comb.pop()

    def getCombinations(self, n, colors):
        self.helper(colors, n, [])
        return self.ans
    
    
res = Solution().getCombinations(2, 3)
print(res)