class Solution:
    def tribonacci(self, n: int) -> int:

        count = 0
        dp = {}

        def backtrack(n):

            if n == 0:
                return 0
            if n == 1 or n == 2:
                return 1
            
            if n in dp:
                return dp[n]
            
            val = (backtrack(n -1 ) + backtrack(n - 2) + backtrack(n - 3))
            dp[n] = val

            return dp[n]
            
        return backtrack(n)