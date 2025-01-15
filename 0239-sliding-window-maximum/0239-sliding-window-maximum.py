from collections import deque
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:

        res = []
        q = deque()

        for idx, num in enumerate(nums):
            while q and num > q[-1]:
                q.pop()
            q.append(num)

            #Check out of bounds and if nums is the correct length
            if idx >= k and nums[idx - k] == q[0]:
                q.popleft()
            
            if idx >= k - 1:
                res.append(q[0])
        
        return res
        
        return res




        
        