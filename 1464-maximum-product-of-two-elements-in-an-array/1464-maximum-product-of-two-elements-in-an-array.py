import heapq
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        pq = []

        for i in nums:
            heapq.heappush(pq, i)
        
        largest = heapq.nlargest(2, pq)
        
        return (largest[0] - 1) * (largest[1] - 1)