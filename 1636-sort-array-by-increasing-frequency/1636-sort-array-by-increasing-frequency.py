class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:

        my_dict = {}

        for num in nums:
            if num in my_dict:
                my_dict[num] += 1
            else:
                my_dict[num] = 1

        sortedList = sorted(nums, key=lambda x: (my_dict[x], -x))

        return sortedList



        