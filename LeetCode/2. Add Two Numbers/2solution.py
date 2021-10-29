# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # keep track of current node
        current = ListNode(0)
        # result, which is the head node
        result = current
        # carry value to the next digit
        carry = 0
        
        # this is obviouos, if either of list is not the end
        # or if the carry is not 0
        while l1 or l2 or carry:
            # add l1 first, move to next node
            if l1:
                carry = carry + l1.val
                l1 = l1.next
            # then add l2, move to next node
            if l2:
                carry = carry + l2.val
                l2 = l2.next
            # integer division to get the carry bit
            # remainder is the result of current digit
            current.next = ListNode(carry % 10)
            carry = carry // 10
            
            # move current node to the next node
            current = current.next
            
        # the first node is dummy value 0, so start from next one
        return result.next