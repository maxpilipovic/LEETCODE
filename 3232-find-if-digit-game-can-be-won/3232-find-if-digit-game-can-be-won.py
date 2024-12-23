class Solution:
    def canAliceWin(self, nums: List[int]) -> bool:

        singleDigits = [1, 2, 3, 4, 5, 6, 7, 8, 9]

        singleSum = 0
        doubleSum = 0

        for i in range(len(nums)):
            if nums[i] in singleDigits:
                singleSum += nums[i]
            else:
                doubleSum += nums[i]
        
        if singleSum == doubleSum:
            return False

        if (singleSum > doubleSum) or (singleSum < doubleSum):
            return True

        