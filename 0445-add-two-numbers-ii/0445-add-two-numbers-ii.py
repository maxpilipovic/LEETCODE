# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        curr = l1
        string = ""
        while curr != None:
            string += str(curr.val)
            curr = curr.next
            

        curr2 = l2
        string2 = ""
        while curr2 != None:
            string2 += str(curr2.val)
            curr2 = curr2.next

        res = int(string) + int(string2)

        #Create our dummy
        dummy = ListNode(0)
        curr3 = dummy

        for char in str(res):
            curr3.next = ListNode(int(char))
            curr3 = curr3.next

        return dummy.next

        