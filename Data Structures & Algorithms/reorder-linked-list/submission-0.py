# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if not head or not head.next:
            return
        
        # find middle
        slow, fast = head, head
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next
        
        curr = slow.next
        prev = slow.next = None

        #reverse second half
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt

        # merge two halfs
        l1, l2 = head, prev
        while l2:
            n1, n2 = l1.next, l2.next
            l1.next = l2
            l2.next = n1
            l1, l2 = n1, n2