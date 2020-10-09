# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        curr = head
        l = 0
        while curr:
            curr = curr.next
            l += 1
        k = l - n
        print(k)
        prev = None
        curr = head
        if k == 0:
            return curr.next if curr else None
        while k > 0:
            prev = curr
            curr = curr.next
            k -= 1
        prev.next = curr.next
        return head