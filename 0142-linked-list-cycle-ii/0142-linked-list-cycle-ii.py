# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:

        curr = head
        curr2 = head

        #While loop to keep looping
        while curr2 is not None and curr2.next is not None:
            
            #Increase fast and slow pointers
            curr = curr.next
            curr2 = curr2.next.next
            
            #Find the start of the cycle 
            #GUARENTEED THEY MEET HALF WAY
            if curr == curr2:
                #Create new pointer
                entry = head

                while entry != curr:
                    entry = entry.next
                    curr = curr.next
                return entry


        return None

        