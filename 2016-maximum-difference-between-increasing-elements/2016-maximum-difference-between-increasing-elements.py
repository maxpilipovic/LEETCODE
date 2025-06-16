class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        
        res = 0

        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):

                if 0 <= i < j < len(nums):
                    diff = abs(nums[j]) - abs(nums[i])
                    res = max(res, diff)

        return res if res != 0 else -1