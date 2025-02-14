class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        
        heapq.heapify(nums) #min-heap by default
        count = 0

        while nums and nums[0] < k:

            if len(nums) < 2:
                break
            
            #Get our values
            x = heapq.heappop(nums)
            y = heapq.heappop(nums)

            #Computation
            ans = (min(x, y) * 2) + max(x, y)

            #Push our value back
            heapq.heappush(nums, ans)

            #Count
            count += 1
        
        return count





