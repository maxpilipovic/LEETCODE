# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:

        slow = head
        fast = head
        #Find the middle point
        while fast != None and fast.next != None:
            slow = slow.next
            fast = fast.next.next

        #Reverse list
        prev = None
        curr = head
        while curr != slow:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        
        #Odd length
        #If fast is None, then odd.
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


        