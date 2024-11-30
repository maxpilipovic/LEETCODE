# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:

        curr1 = list1
        curr2 = list2

        #create new linkedlist to merge
        dummy2 = ListNode()
        dummy = dummy2

        while curr1 != None and curr2 != None:

            if curr1.val <= curr2.val:
                dummy.next = curr1
                curr1 = curr1.next
            else:
                dummy.next = curr2
                curr2 = curr2.next
            #increasing our pointer
            dummy = dummy.next
        
        if curr1 == None:
            dummy.next = curr2
        else:
            dummy.next = curr1
            
        
        return dummy2.next



        