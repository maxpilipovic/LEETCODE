# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if head is None:
            return None

        my_dict = dict()

        curr = head

        while curr != None:
            if curr.val in my_dict:
                my_dict[curr.val] += 1
            else:
                my_dict[curr.val] = 1
            curr = curr.next
        
        #Create a new ListNode
        dummy = ListNode(0)
        curr2 = dummy

        for key, value in my_dict.items():
            if value == 1:
                curr2.next = ListNode(key)
                curr2 = curr2.next
        
        return dummy.next