class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:

        
        minHeap = [-i for i in nums]
        heapq.heapify(minHeap)

        while k > 0:
            topVal = heapq.heappop(minHeap)

            k -= 1
        
        return -(topVal)


        