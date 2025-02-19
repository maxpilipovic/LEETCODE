class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        

        sorted_nums = sorted(nums)
        my_dict = {}
        print(sorted_nums)


        for i, num in enumerate(sorted_nums):
            if num not in my_dict:
                my_dict[num] = i

        print(my_dict)
        
        return [my_dict[num] for num in nums]