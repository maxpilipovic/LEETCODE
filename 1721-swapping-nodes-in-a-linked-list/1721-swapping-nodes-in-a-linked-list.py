# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

        #Create OG pointer
        curr = head

        #Array
        array = []

        while curr != None:
            array.append(curr.val)
            curr = curr.next
        
        print(array)

        #Two pointers
        left = k - 1
        right = len(array) - k

        #####
        #Make the swap
        #temp = array[left]
        #array[left] = array[right]
        #array[right] = temp

        #Python swap
        array[left], array[right] = array[right], array[left]

        #Create new linkedlist and loop
        dummy = ListNode(0)
        curr2 = dummy

        for i in range(len(array)):
            curr2.next = ListNode(array[i])
            curr2 = curr2.next
        
        return dummy.next

        