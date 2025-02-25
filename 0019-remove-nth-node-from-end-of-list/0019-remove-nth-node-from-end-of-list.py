# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:

        curr = head
        array = []

        while curr is not None:
            array.append(curr)
            curr = curr.next
        
        remove = len(array) - n

        #new pointer
        curr2 = head

        if remove == 0:
            curr2 = curr2.next
        else:
            array[remove-1].next = array[remove].next
        return curr2
        