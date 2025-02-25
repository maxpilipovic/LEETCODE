class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        
        my_dict = {0: -1}
        curr = 0
        maxRes = 0

        for i, num in enumerate(nums):

            curr += -1 if num == 0 else 1

            if curr in my_dict:
                maxRes = max(maxRes, i - my_dict[curr])
            else:
                my_dict[curr] = i

        return maxRes


        