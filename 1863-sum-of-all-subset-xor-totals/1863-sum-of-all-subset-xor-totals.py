class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        
        def backtracking(i, currCount):
            if i == len(nums):
                return currCount
            
            includeNums = backtracking(i + 1, currCount ^ nums[i])
            excludeNums = backtracking(i + 1, currCount)

            return includeNums + excludeNums 

        return backtracking(0, 0)