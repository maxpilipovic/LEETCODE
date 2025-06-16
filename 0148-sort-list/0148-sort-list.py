# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        curr = head
        array = []

        while curr != None:
            array.append(curr.val)
            curr = curr.next
        
        print(array)
        array.sort()
        print(array)

        dummy = ListNode(0)
        curr = dummy

        for i in array:
            curr.next = ListNode(i)
            curr = curr.next
        
        return dummy.next

        
