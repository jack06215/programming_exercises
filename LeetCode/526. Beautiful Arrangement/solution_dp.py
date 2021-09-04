from functools import lru_cache
class Solution:   
    def countArrangement(self, n: int) -> int:
        @lru_cache(None)
        def dp(i, mask):
            if i == n:
                return 1
            
            result = 0
            for num in range(n):
                if mask & (1 << num) == 0:
                    if ((num + 1) % (i + 1) == 0 or (i + 1) % (num + 1) == 0):
                        result = result + dp(i + 1, mask | (1 << num))
            return result
        return dp(0, 0)

solution = Solution()
assert(solution.countArrangement(5) == 10)