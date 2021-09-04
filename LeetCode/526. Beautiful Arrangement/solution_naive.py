class Solution(object):
    def countArrangement(self, n: int) -> int:
        perm = [x for x in range(1,n+1)]
        return self.counts(n, perm)
    
    def counts(self, n, perm) -> int:
      # base case
      if n <= 0: 
          return 1

      # try every premutations
      cnt = 0
      for i in range(n):
          if (perm[i] % n == 0) or (n % perm[i] == 0):
              perm[i], perm[n - 1] = perm[n - 1], perm[i]
              cnt = cnt + self.counts(n - 1, perm)
              perm[n - 1], perm[i] = perm[i], perm[n - 1]
      return cnt

solution = Solution()
assert(solution.countArrangement(5) == 10)