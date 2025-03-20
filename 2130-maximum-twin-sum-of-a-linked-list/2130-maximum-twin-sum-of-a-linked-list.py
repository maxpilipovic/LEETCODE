# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:

        res = 0

        #Find mid
        slow = head
        fast = head
        prev = None

        while fast != None and fast.next != None:
            prev = slow
            slow = slow.next
            fast = fast.next.next
        
        slow2 = slow
        prev.next = None

        #Reverse second half
        prev = None
        while slow != None:
            nxt = slow.next
            slow.next = prev
            prev = slow
            slow = nxt

        curr1 = head
        curr2 = prev

        while curr2 != None:
            res = max(res, curr1.val + curr2.val)
            curr1 = curr1.next
            curr2 = curr2.next
        
        return res
        