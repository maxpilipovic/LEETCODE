# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        
        #Nums to hold linkedlist val's in array
        nums = []

        #Stack
        stack = []

        #Initalize pointer
        curr = head

        #Loop and populate nums
        while curr != None:
            nums.append(curr.val)
            curr = curr.next

        #Result
        array = [0] * len(nums)
        
        for i, value in enumerate(nums):
            #While stack is not empty and the top val in stack greater then nums
            while stack and value > nums[stack[-1]]:
                index = stack.pop()
                array[index] = value
            stack.append(i)
    
        return array



        