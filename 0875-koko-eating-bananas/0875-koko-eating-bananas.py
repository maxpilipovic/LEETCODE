class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:

        def helper(mid):
            hours = 0
            for i in piles:
                hours += ceil(i / mid)

            return hours <= h




        left = 1
        right = max(piles)
        result = max(piles)

        while left <= right:

            mid = (left + right) // 2
            if helper(mid):
                result = mid
                right = mid - 1
            else:
                left = mid + 1
        
        return result