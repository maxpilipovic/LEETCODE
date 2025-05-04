from collections import deque
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        #m rows
        #n cols

        dp = {}

        def dfs(row, col):
            
            #Base Case [Get to the end [m - 1] [n- 1]]
            if row == m - 1 and col == n - 1:
                return 1
            
            if (row, col) in dp:
                return dp[(row, col)]
            
            #Bounds
            if row < 0 or row == m or col < 0 or col == n:
                return 0
            
            #Call dfs
            dp[(row, col)] = dfs(row + 1, col) + dfs(row, col + 1)

            return dp[(row, col)]

        return dfs(0, 0)





        