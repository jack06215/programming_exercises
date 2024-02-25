# Problem statement
Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).

For example, given the string "(\[\])\[\]({})", you should return true.

Given the string "(\[)\]" or "((()", you should return false.

# Solution
we can use a stack to keep track of the opening brackets and ensure they are properly closed in the correct order. When we encounter an opening bracket, we push it onto the stack. When we encounter a closing bracket, we check if it matches the type of the opening bracket at the top of the stack. If it does, we pop the opening bracket from the stack; if not, the brackets are not balanced, and we return `false`.

we use a stack to keep track of opening brackets. For each closing bracket, we check if the top of the stack has the corresponding opening bracket. If not, or if the stack is empty when we find a closing bracket, we return `false`. If we finish processing the string and the stack is empty, it means all brackets were balanced, so we return `true`. Otherwise, if the stack is not empty, it means there are unmatched opening brackets, so we return `false`.