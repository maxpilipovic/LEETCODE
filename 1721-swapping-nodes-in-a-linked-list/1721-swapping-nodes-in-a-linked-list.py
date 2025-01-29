# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

        #Create OG pointer and second pointer for swap
        curr = head
        curr2 = head
        
        #Create counter to keep track of left pointer
        left = k

        #Traverse list to find length
        length = 0
        while curr != None:
            curr = curr.next
            length += 1
        
        #End pointer to remove
        right = length - k + 1

        #Boolean variables for flags
        f = False
        s = False

        #Traverse list now and swap
        tick = 0
        while curr2 != None:
            tick += 1
        
            if tick == left:
                first = curr2
                f = True
            
            if tick == right:
                second = curr2
                right = True
            
            if f == True and s == True:
                break
            curr2 = curr2.next
        
        #Swap
        first.val, second.val = second.val, first.val
        
        return head
            

            

        


        

            
            



        
        