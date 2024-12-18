class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:

        import heapq

        pq = []

        for idx, value in enumerate(nums):
            heappush(pq, (value, idx))

        while k > 0:
            value, idx = heappop(pq)
            value *= multiplier
            heappush(pq, (value, idx))
            k -= 1
        
        while pq:
            value, idx = heappop(pq)
            nums[idx] = value

        return nums
            
            


        