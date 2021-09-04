from typing import List

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        rows = {}
        for index, row in enumerate(mat):
            rows[index] = sum(row)
        return sorted(rows, key=rows.get)[:k]

s = Solution()
arr = [[1,1,0,0,0],
       [1,1,1,1,0],
       [1,0,0,0,0],
       [1,1,0,0,0],
       [1,1,1,1,1]]
k = 3
print(s.kWeakestRows(arr, k))