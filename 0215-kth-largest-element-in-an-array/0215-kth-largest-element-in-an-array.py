import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        
        min_heap = nums[:]
        heapq.heapify(min_heap)
        print(min_heap)

        while len(min_heap) > k-1:
            ans = heapq.heappop(min_heap)
        
        return ans