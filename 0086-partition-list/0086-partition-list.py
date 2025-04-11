# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        if not head:
            return None

        curr = head

        dummy1 = ListNode()
        curr1 = dummy1

        dummy2 = ListNode()
        curr2 = dummy2

        #Seperate two lists
        while curr != None:

            if curr.val >= x:
                curr2.next = ListNode(curr.val)
                curr2 = curr2.next
            else:
                curr1.next = ListNode(curr.val)
                curr1 = curr1.next
            
            curr = curr.next
        
        #Connect
        curr1.next = dummy2.next

        return dummy1.next
        


        