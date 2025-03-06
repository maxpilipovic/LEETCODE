class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        
        if n == 0:
            return True
            
        for i in range(len(flowerbed)):
            
            if flowerbed[i] == 0:

                leftEmpty = (i == 0) or flowerbed[i - 1] == 0
                rightEmpty = (i == len(flowerbed) - 1 or flowerbed[i + 1] == 0)

                if leftEmpty and rightEmpty:
                    n -= 1
                    flowerbed[i] = 1
                
                if n == 0:
                    return True
        
        return False
        