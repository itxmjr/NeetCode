# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        def insertNode(lst, node):
            tmp = lst.next
            copyNode = ListNode(node.val, node.next)
            lst.next = copyNode
            copyNode.next = tmp
            return copyNode
        
        if not list1 and not list2: return None
        if not list1: return list2
        if not list2: return list1

        if list1.val <= list2.val:
            head = list1
            curr1 = list1
            curr2 = list2
        else:
            head = list2
            curr1 = list2
            curr2 = list1
        
        while curr2:
            if not curr1.next:
                curr1.next = curr2
                break
            elif curr1.next.val <= curr2.val:
                curr1 = curr1.next
            else:
                curr1 = insertNode(curr1, curr2)
                curr2 = curr2.next

        return head
