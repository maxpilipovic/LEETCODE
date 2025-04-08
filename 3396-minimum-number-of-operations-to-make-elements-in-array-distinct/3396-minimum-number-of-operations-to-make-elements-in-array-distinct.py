class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        
        if len(set(nums)) == len(nums):
            return 0
    
        count = 0

        while len(nums) != len(set(nums)):
            count += 1

            if len(nums) >= 3:
                nums = nums[3:]
            else:
                nums = []
        
        return count

            

        