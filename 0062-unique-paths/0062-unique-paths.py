from collections import deque
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        #m rows
        #n cols

        dp = [1] * n
        directions = [(1, 0), (0, 1)]

        for i in range(1, m):

            for j in range(1, n):
                dp[j] += dp[j - 1]
        
        return dp[-1]





        