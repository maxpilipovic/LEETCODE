# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:

        curr = head
        array = []
        res = 0

        while curr != None:
            array.append(curr.val)
            curr = curr.next

        #Get our last value in array
        last = len(array) - 1

        #Loop through and check max
        first = head

        while first != None:
            ans = first.val + array[last]

            res = max(res, ans)

            first = first.next
            last -= 1
        
        return res