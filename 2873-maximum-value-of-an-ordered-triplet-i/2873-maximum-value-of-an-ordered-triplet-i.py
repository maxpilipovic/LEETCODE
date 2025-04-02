class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:

        maxVal = 0
        left = nums[0]

        for j in range(1, len(nums)):

            if nums[j] > left:
                left = nums[j]
            
            for k in range(j + 1, len(nums)):
                ans = ((left - nums[j]) * nums[k])
                maxVal = max(maxVal, ans)
        
        return maxVal
                   



        