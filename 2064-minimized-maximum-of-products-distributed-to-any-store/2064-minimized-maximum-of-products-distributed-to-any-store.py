class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        def distribute(mid):

            requiredStores = 0

            for i in quantities:
                storesNeeded = ceil(i / mid)
                requiredStores += storesNeeded

            return requiredStores <= n

        
        left = 1
        right = max(quantities)

        while left < right:
            mid = (left + right) // 2

            if distribute(mid):
                right = mid
            else:
                left = mid + 1

        return left