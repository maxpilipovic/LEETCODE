class Solution:
    def sortColors(self, nums: List[int]) -> None:

        my_dict = {0: 0, 1: 0, 2: 0}
        nums2 = []

        for i in range(len(nums)):
            if nums[i] in my_dict:
                my_dict[nums[i]] += 1
        
        
        index = 0
        for color in my_dict:
            for _ in range(my_dict[color]):
                nums[index] = color
                index += 1

        
        
        