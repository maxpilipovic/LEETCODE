class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        
        low = 0
        high = len(nums) - 1

        while low <= high:

            mid = low + (high - low) // 2
            
            
            #Safe neighbors within bounds
            left = nums[mid - 1] if mid > 0 else float('-inf')
            right = nums[mid + 1] if mid < len(nums) - 1 else float('-inf')

            if left < nums[mid] and right < nums[mid]:
                return mid
            elif right > nums[mid]:
                low = mid + 1
            else:
                high = mid - 1

            