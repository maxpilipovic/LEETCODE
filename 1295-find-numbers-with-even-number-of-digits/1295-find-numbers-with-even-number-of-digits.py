class Solution:
    def findNumbers(self, nums: List[int]) -> int:

        count = 0

        for i in range(len(nums)):

            valLength = len(str(nums[i]))

            if valLength % 2 == 0:
                count += 1
        
        return count
        