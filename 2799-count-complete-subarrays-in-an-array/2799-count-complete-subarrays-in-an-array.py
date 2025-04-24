from collections import defaultdict
class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        
        distinct = len(set(nums))
        count = 0

        def recursive(index):
            
            nonlocal count

            #Base Case
            if index > len(nums) - 1:
                return
            
            currSet = set()

            for i in range(index, len(nums)):
                currSet.add(nums[i])

                if len(currSet) == distinct:
                    count += 1
            
            return recursive(index + 1)
        
        recursive(0)
        
        return count








            

        