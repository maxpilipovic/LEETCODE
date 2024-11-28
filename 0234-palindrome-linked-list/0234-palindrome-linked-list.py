# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:

        curr = head
        array = []

        while curr != None:
            array.append(curr.val)
            curr = curr.next
        
        reverseArray = list(reversed(array))

        if array == reverseArray:
            return True
        else:
            return False
        
        

        