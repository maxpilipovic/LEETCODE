class Solution:
    def rob(self, nums: List[int]) -> int:


        my_dict = {}

        def robHouse(i):

            #Base Case
            if i > len(nums) - 1:
                return 0

            #Recursive WITH DP
            if i in my_dict:
                return my_dict[i]

            #Rob
            robIt = nums[i] + robHouse(i + 2)

            #Skip
            skipIt = robHouse(i + 1)
            
            my_dict[i] = max(robIt, skipIt)

            return my_dict[i]


        return robHouse(0)
        
        