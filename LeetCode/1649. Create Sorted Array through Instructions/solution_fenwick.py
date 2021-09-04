from typing import List

MOD = 100_000_000_7
class Solution:
    def createSortedArray(self, instructions: List[int]) -> int:
        N = max(instructions)
        cc = [0] * (N + 1)
        
        # Fenwick tree update and query method
        def update(x):
            while x <= N:
                cc[x] += 1
                x += -x & x
        def query(x):
            ans = 0
            while x > 0:
                ans += cc[x]
                x -= -x & x
            return ans

        ans = 0
        for i, n in enumerate(instructions):
            ans += min(query(n - 1), i - query(n))
            update(n)
        return ans % MOD

s = Solution()
input_seq = [1,5,6,2]
print(s.createSortedArray(input_seq))