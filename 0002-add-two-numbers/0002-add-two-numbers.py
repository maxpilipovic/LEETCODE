# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        
        curr1 = l1
        curr2 = l2

        num1 = ''
        num2 = ''

        while curr1 is not None:
            #append that value
            num1 += str(curr1.val) 
            curr1 = curr1.next

        while curr2 is not None:
            num2 += str(curr2.val)
            curr2 = curr2.next

        reversed1 = num1[::-1]
        reversed2 = num2[::-1]
        #print(num2)
        #add together
        ans = str(int(reversed1) + int(reversed2))
        print(ans)
        #print(ans)
        
        #dummy
        res = ListNode()
        current = res
        for char in reversed(ans):
            current.next = ListNode(int(char))
            current = current.next
        return res.next
