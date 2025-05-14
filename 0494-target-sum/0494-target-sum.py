class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:

        memo = {}

        def backtrack(i, total):

            #Base Case
            if (i, total) in memo:
                return memo[(i, total)]
            
            #Base Case
            if i == len(nums):
                return 1 if total == target else 0
            
            plus = backtrack(i + 1, total + nums[i])
            minus = backtrack(i + 1, total - nums[i])

            memo[(i, total)] = plus + minus

            return memo[(i, total)]
        

        return backtrack(0, 0)
        