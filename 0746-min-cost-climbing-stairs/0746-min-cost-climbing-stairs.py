class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        
        dp = {}

        def backtrack(i):

            if i >= len(cost):
                return 0
            
            if i in dp:
                return dp[i]

            dp[i] = cost[i] + min(backtrack(i + 1), backtrack(i + 2))
            return dp[i]
        
        return min(backtrack(0), backtrack(1))

