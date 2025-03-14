class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:

        low = 0
        high = len(arr) - 1


        while low < high:

            #Calculate mid
            mid = low + (high - low) // 2

            if arr[mid] < arr[mid + 1]: #Peak is to the right
                low = mid + 1
            else: #Peak is at current or lower
                high = mid
        
        return low

        