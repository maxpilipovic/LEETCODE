# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:

        curr = head
        curr2 = head

        while curr2 is not None and curr2.next is not None:
            curr = curr.next
            curr2 = curr2.next.next

            #Base case
            if curr == curr2:
                return True
        
        return False
        