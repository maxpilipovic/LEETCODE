import heapq
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:

        max_heap = [-x for x in stones]
        print(max_heap)
        heapq.heapify(max_heap)
        print(max_heap)

        #Take two stones.
        while len(max_heap) > 1:

            x = -heapq.heappop(max_heap)
            y = -heapq.heappop(max_heap)

            if x != y:
                ans = abs(y - x)
                heapq.heappush(max_heap, -ans)
        
        return -max_heap[0] if max_heap else 0
        