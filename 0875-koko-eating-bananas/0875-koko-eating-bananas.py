class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:

        left = 1
        right = max(piles)
        res = right

        while left <= right:
            k = (right + left) // 2
            totalBananas = 0

            hours = sum(math.ceil(ban / k) for ban in piles)
            
            if hours <= h:
                #Try something smaller
                res = k
                right  = k - 1
            else:
                left = k + 1
        
        return res



        
