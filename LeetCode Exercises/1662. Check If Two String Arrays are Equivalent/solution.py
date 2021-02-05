class Solution:
    def arrayStringsAreEqual(self, word1: list, word2: list) -> bool:
        return ''.join(word1) == ''.join(word2)

arr1 = ["ab", "c"]
arr2 = ["a", "bc"]
solution = Solution()

print(solution.arrayStringsAreEqual(arr1, arr2))