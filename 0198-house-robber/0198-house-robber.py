class Solution:
    def rob(self, nums: List[int]) -> int:

        dp = {}

        def backtrack(i):

            if i >= len(nums):
                return 0
            
            if i in dp:
                return dp[i]

            rob = nums[i] + backtrack(i + 2)
            skip = backtrack(i + 1)

            dp[i] = max(rob, skip)

            return dp[i]

        return backtrack(0)
        