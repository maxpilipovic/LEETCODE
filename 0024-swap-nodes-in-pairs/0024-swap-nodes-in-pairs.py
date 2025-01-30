# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        #Creates a new Node
        dummy = ListNode(0)

        #This makes the next node = head of og list
        dummy.next = head

        #Prev node to swap (Starts at node before)
        prev = dummy

        #Curr node to swap (Starts at head) - one in front of prev
        curr = head

        while curr != None and curr.next != None:
            
            #Identify the nodes to swap
            first = curr
            second = curr.next

            #Swap
            prev.next = second
            first.next = second.next
            second.next = first

            #Move to next pair
            prev = first
            curr = first.next
        
        return dummy.next
           
        