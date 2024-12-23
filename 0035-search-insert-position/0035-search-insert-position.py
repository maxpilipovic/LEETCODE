class Solution(object):
    def searchInsert(self, nums, target):

        #binary search

        low = 0
        high = len(nums) - 1

        while low <= high:
            mid = (low + high) // 2

            if target == nums[mid]:
                #do whatever
                return mid
            elif target > nums[mid]:
                #do whatever
                low = mid + 1
            elif target < nums[mid]:
                #do whatever
                high = mid - 1
        return low
        