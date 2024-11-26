class Solution:
    def missingNumber(self, nums: List[int]) -> int:

        sortedNums = sorted(nums)
        print(sortedNums)

        for i in range(len(nums) - 1):
            if sortedNums[i] + 1 != sortedNums[i+1]:
                return sortedNums[i] + 1

        #if we loop through and are at the end of the array.
        #Check first and last number
        if sortedNums[0] != 0:
            return 0
        return sortedNums[-1] + 1

            
        
        