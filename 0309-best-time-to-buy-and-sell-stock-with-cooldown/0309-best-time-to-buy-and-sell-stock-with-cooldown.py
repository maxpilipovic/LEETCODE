class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        res = 0
        memo = {}

        def backtrack(i, hold):

            #Base Case
            if i >= len(prices):
                #Do something here
                return 0
            
            #Dp
            if (i, hold) in memo:
                return memo[(i, hold)]

            #Option 1: Cooldown
            cooldown = backtrack(i + 1, hold)

            #Buy
            if hold:
                #Option 2: Sell
                sell = prices[i] + backtrack(i + 2, False)
                memo[(i, hold)] = max(cooldown, sell)
            else:
                #Option 3: Buy
                buy = -prices[i] + backtrack(i + 1, True)
                memo[(i, hold)] = max(cooldown, buy)

            return memo[(i, hold)]


        return backtrack(0, False)




            