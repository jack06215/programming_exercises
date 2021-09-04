class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        
        # empty list
        if not head:
            return None        
        
        # single list
        if head == None or head.next == None:
            return head
        
        # return next non-duplicate element
        curr_val = head.val
        if (curr_val != head.next.val):
            head.next = self.deleteDuplicates(head.next)
            return head
        
        # we have duplicate so forward one step
        while(head and head.val == curr_val):
            head = head.next
        
        # checks next element
        return self.deleteDuplicates(head)