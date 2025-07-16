class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        currMin = nums[0]
        currMax = nums[0]
        globalMax = nums[0]


        for num in range(1, len(nums)):

            if nums[num] < 0:
                currMin, currMax = currMax, currMin

            currMin = min(nums[num], currMin * nums[num])
            currMax = max(nums[num], currMax * nums[num])

            globalMax = max(globalMax, currMax)

        return globalMax

