# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:

        #If empty
        if head is None and left == 1 and right == 1:
            return head

        dummy = ListNode(0)
        dummy.next = head
        prev = dummy

        for i in range(0, left - 1):
            prev = prev.next
        

        #Start reversing from prev
        curr = prev.next

        #Loops for (right - left) times
        for _ in range(right - left):
            temp = curr.next
            curr.next = temp.next
            temp.next = prev.next
            prev.next = temp





        

        