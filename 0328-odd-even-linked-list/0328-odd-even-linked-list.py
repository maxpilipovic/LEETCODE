# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if not head:
            return None
        
        #If its not greater then 2 values
        
        even = head.next
        even_head = head.next
        odd = head

        while even != None and even.next != None:
            odd.next = even.next
            odd = odd.next

            even.next = odd.next
            even = even.next

        
        odd.next = even_head

        return head