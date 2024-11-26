class Solution:
    def singleNumber(self, nums: List[int]) -> int:

        my_dict = dict()

        for i in range(len(nums)):
            if nums[i] in my_dict:
                my_dict[nums[i]] += 1
            else:
                my_dict[nums[i]] = 1
        
        for key, value in my_dict.items():
            if value == 1:
                return key

        