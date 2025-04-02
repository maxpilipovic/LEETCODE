class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:

        maxVal = 0

        for i in range(len(nums)):
            for j in range(len(nums)):
                for k in range(len(nums)):
                    if i < j < k:
                        ans = ((nums[i] - nums[j]) * nums[k])
                        print(ans)

                        if ans < 0:
                            ans = 0
                    
                        maxVal = max(maxVal, ans)
        
        return maxVal


        