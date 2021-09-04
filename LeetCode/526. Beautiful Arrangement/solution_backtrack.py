class Solution(object):
    def countArrangement(self, n: int) -> int:
        self.visited = [False] * n
        self.count = 0
        self.n = n

        def dfs(pos):
            if pos == 0:
                self.count = self.count + 1
                return None

            for i in range(1, self.n + 1):
                if (self.visited[i - 1] or (pos % i != 0 and i % pos != 0)):
                    continue

                self.visited[i - 1] = True
                dfs(pos - 1)
                self.visited[i - 1] = False

        dfs(n)
        return self.count

solution = Solution()
assert(solution.countArrangement(5) == 10)