# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        dummy = ListNode(0, head)  # Dummy node to handle edge cases
        fast = slow = dummy  

        for _ in range(n):
            fast = fast.next  

        # Move both fast and slow pointers until fast reaches the end
        while fast.next:
            fast = fast.next
            slow = slow.next

        # Remove the Nth node
        slow.next = slow.next.next  

        return dummy.next  # Return the updated list


        