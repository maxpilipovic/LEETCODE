class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        #Memo

        dp = {}

        def dfs(rem):

            #Base Case
            if rem < 0:
                return float('inf')

            if rem == 0:
                return 0
            
            if rem in dp:
                return dp[rem]
            
            #Recursive
            minCoin = float('inf')

            for coin in coins:
                res = dfs(rem - coin)

                if res != float('inf'):
                    minCoin = min(minCoin, res + 1)

            dp[rem] = minCoin
            
            return dp[rem]

        res = dfs(amount)

        return res if res != float('inf') else -1