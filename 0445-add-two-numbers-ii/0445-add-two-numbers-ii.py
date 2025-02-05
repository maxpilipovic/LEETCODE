# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        #Reverse l1 here
        curr = l1
        prev = None

        while curr != None:
            nxt = curr.next
            #Changes the link
            curr.next = prev
            prev = curr
            curr = nxt
        
        #New Head
        l1 = prev

        #Reverse l2 here
        curr2 = l2
        prev2 = None

        while curr2 != None:
            nxt2 = curr2.next
            curr2.next = prev2
            prev2 = curr2
            curr2 = nxt2

        #New Head
        l2 = prev2

        #Basic 2ndGrade Arithmetic
        dummy = ListNode(0)
        curr3 = dummy
        carry = 0


        while l1 or l2 or carry:
            
            #Manage out of bounds
            integer1 = l1.val if l1 else 0
            integer2 = l2.val if l2 else 0
            
            #Add both integers and carry
            res = integer1 + integer2 + carry

            #RELOOK AT THIS...
            carry = res // 10
            digit = res % 10
            

            #Create a new node
            curr3.next = ListNode(digit)
            curr3 = curr3.next

            #Move if they exist
            if l1: l1 = l1.next
            if l2: l2 = l2.next
    
        #REVERSE AGAIN

        curr = dummy.next
        prev = None

        while curr != None:

            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        
        return prev






        