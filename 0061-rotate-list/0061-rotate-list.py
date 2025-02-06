# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        
        if not head or not head.next or k == 0:
            return head

        #Find length
        length = 1
        tail = head
        while tail.next != None:
            tail = tail.next
            length += 1
        
        #Optimzation
        k = k % length
        if k == 0:
            return head
        
        #Step 3 - Finding the new tail
        new_tail = head
        for _ in range(length - k - 1):
            new_tail = new_tail.next

        #Reconstruct
        new_head = new_tail.next
        new_tail.next = None
        tail.next = head

        return new_head


        



        


        