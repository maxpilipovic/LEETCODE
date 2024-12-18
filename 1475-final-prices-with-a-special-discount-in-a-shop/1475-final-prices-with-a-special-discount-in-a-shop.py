class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        
        array = []

        for i in range(len(prices)):
            array.append(prices[i])

            #look for price
            for j in range(i + 1, len(prices)):
                if prices[j] <= prices[i]:
                    array[i] = (prices[i] - prices[j])
                    break
        
        return array

        