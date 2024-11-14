class Solution(object):
    def search(self, nums, target):

        left = 0
        right = len(nums) - 1

        def binarySearch(left, right, target, nums):

            while left <= right:
                mid = (left + right) / 2

                if nums[mid] == target:
                    return mid

                #target greater, ignore left half
                elif nums[mid] < target:
                    left = mid + 1
                #target lesser, ignore right half
                else:
                    right = mid - 1
            
            return -1
        
        return binarySearch(left, right, target, nums)
        