# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if head is None:
            return None
        
        curr = head
        fast = head.next

        #increment
        
        while curr != None and fast != None:
            if curr.val == fast.val:
                curr.next = fast.next
            else:
                curr = fast

            fast = fast.next

        return head



        