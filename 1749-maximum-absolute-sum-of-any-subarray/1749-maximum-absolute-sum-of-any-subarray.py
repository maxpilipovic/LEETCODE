class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:

        maxSum = 0
        minSum = 0
        
        currMax = 0
        currMin = 0

        for i in range(len(nums)):
            currMax = max(nums[i], currMax + nums[i])
            currMin = min(nums[i], currMin + nums[i])

            maxSum = max(maxSum, currMax)
            minSum = min(minSum, currMin)
        

        return max(abs(minSum), abs(maxSum))