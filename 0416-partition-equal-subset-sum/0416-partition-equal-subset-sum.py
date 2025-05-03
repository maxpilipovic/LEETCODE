class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        
        dp = {}

        sumVal = sum(nums)
        target = sumVal // 2

        if sumVal % 2 != 0:
            return False
        
        def recursion(i, currSum):

            #Base
            if i > len(nums) - 1 or currSum > target:
                return False
            
            if currSum == target:
                return True
            
            if (i, currSum) in dp:
                return dp[(i, currSum)]

            
            dp[(i, currSum)] = recursion(i + 1, currSum + nums[i]) or recursion(i + 1, currSum)
            return dp[(i, currSum)]

        
        return recursion(0, 0)



            
        

        