class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:


        left = 0
        res = 0

        curr = 0
        for right in range(len(nums)):
            
            while curr & nums[right] != 0:
                curr = curr ^ nums[left] #XOR
                left += 1
            
            #Calculate Window Size
            length = (right - left) + 1

            #Update our res
            res = max(res, length)

            #Set bits
            curr = curr | nums[right]
        
        return res