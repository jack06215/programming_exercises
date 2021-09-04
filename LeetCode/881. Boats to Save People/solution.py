class Solution:
    def numRescueBoats(self, people: list, limit: int) -> int:
        people = sorted(people)
        current = 0
        tail = len(people) - 1
        result = 0
        # "<=" but not "<" because we need to consider
        # where only 1 person is on the boat
        while (current <= tail):
            if people[current] + people[tail] <= limit:
                current = current + 1
            tail = tail - 1
            result = result + 1
        
        return result

solution = Solution()
input_seq = [3,2,2,1]
limit = 3
print(solution.numRescueBoats(input_seq, limit))