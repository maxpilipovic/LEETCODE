# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:
        

        curr = head
        binaryStr = ""

        while curr:
            binaryStr += str(curr.val)
            curr = curr.next
        
        return int(binaryStr, 2)