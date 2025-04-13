import heapq
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        max1 = 0
        max2 = 0

        for i in nums:
            if i >= max1:
                max2 = max1
                max1 = i
        
        return (max1 - 1) * (max2 - 1)