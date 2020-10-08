# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # Approach 1 - Iterative
        '''p = None
        c = a = head
        while c:
            a = c.next
            c.next = p
            p = c
            c = a
        head = p
        return head'''
        
        # Approach 2 - Recursive
        def rev(c, p):
            if not c.next:
                self.xx = c
                c.next = p
                return
            a = c.next
            c.next = p
            rev(a, c)
        
        self.xx = None
        if not head:
            return
        rev(head, None)
        return self.xx