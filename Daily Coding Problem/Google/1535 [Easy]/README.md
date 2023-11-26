# Problem statement
Good morning! Here's your coding interview problem for today.

This problem was recently asked by Google.

Given a list of numbers and a number `k`, return whether any two numbers from the list add up to `k`.

For example, given `[10, 15, 3, 7]` and `k` of `17`, return true since `10 + 7` is `17`.

Bonus: Can you do this in one pass?

# Solution
An `unordered_map` (hash map) named `seen` is used to keep track of the numbers encountered so far. For each number in the list, the code checks whether the complement (k - num) exists in `seen`. If it does, the function returns `true`. Otherwise, the current number is added to `seen` and the search continues. This approach also achieves the task in one pass through the list.