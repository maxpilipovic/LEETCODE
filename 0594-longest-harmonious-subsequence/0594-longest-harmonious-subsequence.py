class Solution:
    def findLHS(self, nums: List[int]) -> int:

        my_dict = Counter(nums)
        maxLength = 0
        count = 0

        for key in my_dict.keys():
            if key + 1 in my_dict:
                count = my_dict[key] + my_dict[key + 1]
            maxLength = max(maxLength, count)

        return maxLength 





        