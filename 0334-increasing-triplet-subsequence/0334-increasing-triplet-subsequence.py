class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:

        for i in range(len(nums)):
            for j in range(len(nums)):
                for k in range(len(nums)):

                    if i < j < k and nums[i] < nums[j] < nums[k]:
                        return True
        
        return False
        