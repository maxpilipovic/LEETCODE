# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        curr = head
        array = []

        #Loop through linkedlist
        while curr is not None:
            array.append(curr.val)
            curr = curr.next
        
        #Sort
        array.sort()

        #Create dummy node and loop through
        dummy = ListNode(0)
        curr2 = dummy

        #Loop through and create new linked list with sorted values
        for i in array:
            curr2.next = ListNode(i)
            curr2 = curr2.next
        
        return dummy.next
        