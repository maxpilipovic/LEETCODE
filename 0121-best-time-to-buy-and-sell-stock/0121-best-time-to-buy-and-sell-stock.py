class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minValue = float('inf')  # Start with a very large value
        maxProfit = 0  # To store the maximum profit

        array = []
        minV = 0

        # Find the minimum value and its index
        for i in range(len(prices)):
            if prices[i] < minValue:
                minValue = prices[i]
                minV = i  # Update the index of the minimum value

        # Collect all prices after the minimum value
        for i in range(minV, len(prices)):
            if prices[i] > minValue:
                array.append(prices[i])

        # Calculate the maximum profit
        if array:
            maxValue = max(array)
            maxProfit = maxValue - minValue

        return maxProfit

                


        



        