# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        

        #If empty
        if head is None and left == 1 and right == 1:
            return head

        array = []
        curr = head
        
        #Loops and adds values to res array
        while curr != None:
            array.append(curr.val)
            curr = curr.next 
        
        res = []
        #Do the left part
        for i in range(0, left - 1):
            res.append(array[i])
        
        middle = []
        #Do the middle part
        middle = array[left - 1: right]
        middle.reverse()
        res.extend(middle)

        #Do the right part
        for i in range(right, len(array), 1):
            res.append(array[i])

        curr2 = head
        counter = 0
        while curr2 != None:
            curr2.val = res[counter]
            counter += 1
            curr2 = curr2.next

        return head

        

        