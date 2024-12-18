class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        
        count = k

        while count > 0:
            
            minValue = float('inf')
            index = 0

            #find min value
            for i in range(len(nums)):
                if nums[i] < minValue:
                    minValue = nums[i]
                    index = i

            #put back in nums array
            nums[index] = minValue * multiplier

            #decrease count
            count -= 1
        
        return nums
            


        