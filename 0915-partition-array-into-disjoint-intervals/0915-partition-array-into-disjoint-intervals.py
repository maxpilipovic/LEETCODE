class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        
        if not nums:
            return 0
        
        currMax = nums[0]
        leftMax = nums[0]
        pIdx = 0

        for i in range(1, len(nums)):
            currMax = max(currMax, nums[i])

            if nums[i] < leftMax:
                pIdx = i
                leftMax = currMax

        return pIdx + 1






