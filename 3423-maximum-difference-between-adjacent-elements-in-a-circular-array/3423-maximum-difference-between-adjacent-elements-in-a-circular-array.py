class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        

        right = 1
        maxNum = 0
        for left in nums:
            
            #Wrap
            if right >= len(nums):
                right = 0

            #Calc ab diff
            abdiff = abs(left - nums[right])
            maxNum = max(maxNum, abdiff)

            #Increase right pointer
            right += 1
        
        return maxNum