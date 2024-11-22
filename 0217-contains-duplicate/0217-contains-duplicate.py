class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hashy = set()

        for i in range(len(nums)):
            hashy.add(nums[i])

        if len(hashy) == len(nums):
            return False
        else:
            return True
        