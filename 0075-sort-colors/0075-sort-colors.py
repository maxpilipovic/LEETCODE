class Solution:
    def sortColors(self, nums: List[int]) -> None:
        
        left = 0

        for color in range(len(nums)):
            minNum = float('inf')
            index = 0
            for right in range(color, len(nums)):

                if nums[right] < minNum:
                    minNum = nums[right]
                    index = right
            
            temp = nums[color]
            nums[color] = minNum
            nums[index] = temp
                

