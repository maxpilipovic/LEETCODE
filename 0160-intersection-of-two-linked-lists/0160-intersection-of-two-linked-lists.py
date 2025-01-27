# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        
        #If empty
        if not headA or not headB:
            return None
        
        curr1 = headA
        curr2 = headB

        #Pointers dont equal each other. If curr1 is not None, curr1.next else if curr1 is None, curr1 = headB
        while curr1 != curr2:
            curr1 = curr1.next if curr1 else headB
            curr2 = curr2.next if curr2 else headA
        
        return curr1
            
        