class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        #empty
        if not nums:
            return 0

        #sort
        nums.sort()
        currentStreak = 1
        maxNum = 0

        my_dict = dict()

        #Loop through nums
        for i in range(len(nums) - 1):
            if nums[i] + 1 == nums[i + 1]:
                currentStreak += 1
            else:
                maxNum = max(maxNum, currentStreak)
                currentStreak = 1
        
        return max(maxNum, currentStreak)
