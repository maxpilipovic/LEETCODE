# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:

        curr = head
        curr2 = head

        while curr2 is not None and curr2.next is not None:
            curr = curr.next
            curr2 = curr2.next.next

        return curr



        