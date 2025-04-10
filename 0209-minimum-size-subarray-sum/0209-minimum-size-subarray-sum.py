class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:

        res = float('inf')
        left = 0
        curr = 0

        for right in range(len(nums)):
            curr += nums[right]

            while curr >= target:
                length = (right - left) + 1
                res = min(res, length)

                curr -= nums[left]
                left += 1
        
        return res if res != float('inf') else 0




        