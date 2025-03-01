class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:

        res = [0] * len(nums)
        right = len(nums) - 1
        j = 0

        for i in range(len(nums) - 1):

            if nums[i] == nums[i + 1]:
                nums[i] = nums[i] * 2
                nums[i + 1] = 0
        
        print(nums)

        for num in range(len(nums)):
            if nums[num] != 0:
                res[j] = nums[num]
                j += 1
        

        return res
                

        