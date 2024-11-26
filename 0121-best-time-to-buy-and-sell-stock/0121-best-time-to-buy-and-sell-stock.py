class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        

        minValue = prices[0]
        profit = 0

        for i in range(len(prices)):
            profit = max(profit, prices[i] - minValue)
            minValue = min(minValue, prices[i])

        return profit
                


        



        