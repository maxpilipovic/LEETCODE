class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        freqMap = Counter(nums)
        print(freqMap)

        heap = []

        for key, value in freqMap.items():
            heapq.heappush(heap, (value, key))

            if len(heap) > k:
                heapq.heappop(heap)
        
        #List comprehension
        return [v for _, v in heap]

