class Solution:
    def canSortArray(self, nums: List[int]) -> bool:

        swapped = True
        
        #while swapped is true
        while swapped:
            swapped = False
            for i in range(len(nums) - 1):
                #check bit counts
                bit1 = nums[i].bit_count()
                bit2 = nums[i+1].bit_count()

                #check if value is greater and bit count is greater
                if bit1 == bit2 and nums[i+1] < nums[i]:
                    temp = nums[i]
                    nums[i] = nums[i + 1]
                    nums[i + 1] = temp
                    swapped = True

        print(nums)
        #check if sorted in ascending
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                return False
        
        return True
            


                



        