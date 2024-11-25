class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        #initalize right and left product

        result = [1] * len(nums)

        left_product = 1
        for i in range(len(nums)):
            result[i] = left_product
            left_product *= nums[i]

        right_product = 1
        for i in range(len(nums) - 1, -1, -1):
            result[i] *= right_product
            right_product *= nums[i]

        return result
        




        left_product = 1





        
        