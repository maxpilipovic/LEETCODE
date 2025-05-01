class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        dp_max = [0] * len(nums)
        dp_min = [0] * len(nums)

        totalVal = nums[0]
        dp_max[0] = nums[0]
        dp_min[0] = nums[0]

        for i in range(1, len(nums)):
            num = nums[i]

            dp_max[i] = max(num, dp_max[i-1] * num, dp_min[i-1] * num)
            dp_min[i] = min(num, dp_max[i-1] * num, dp_min[i-1] * num)
            totalVal = max(totalVal, dp_max[i])

        return totalVal
            



        