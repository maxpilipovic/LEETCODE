from collections import defaultdict
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        
        #Find our maxVal
        maxVal = max(nums)
        left = 0
        count = 0
        freq = 0


        for right in range(len(nums)):

            if nums[right] == maxVal:
                freq += 1

            while freq >= k:

                if nums[left] == maxVal:
                    freq -= 1
                left += 1
            
            count += left #Non inuiitive

        
        return count

                
        










        
        