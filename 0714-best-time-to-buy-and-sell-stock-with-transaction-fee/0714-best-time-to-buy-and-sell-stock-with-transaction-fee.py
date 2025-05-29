class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:

        dp = {}

        def backtrack(i, flag):
            

            #Base Case
            if i >= len(prices):
                return 0
            
            if (i, flag) in dp:
                return dp[(i, flag)]
            
            #3 States, Buy, Sell, Skip

            #Skip
            skip = backtrack(i + 1, flag)

            #Buy
            if not flag:
                buy = backtrack(i + 1, True) - prices[i]
                dp[(i, flag)] = max(skip, buy)
            
            #Sell
            else:
                sell = backtrack(i + 1, False) + prices[i] - fee
                dp[(i, flag)] = max(skip, sell)
            
            return dp[(i, flag)]

            

        return backtrack(0, False)

        