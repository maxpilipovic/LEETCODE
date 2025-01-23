# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        
        #empty
        if not head or not head.next:
            return True
        
        #find mid point
        fast = head
        slow = head
        while fast != None and fast.next != None:
            slow = slow.next
            fast = fast.next.next

        #reverse first half
        prev = None
        curr = head
        while curr != slow:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt


        #handles odd-length (skip middle)
        #if Fast is None, odd list.
        if fast:
            slow = slow.next

        #compare
        left = prev
        right = slow 
        while left and right != None:
            if left.val != right.val:
                return False
            left = left.next
            right = right.next
        return True





        

        
        
        

        