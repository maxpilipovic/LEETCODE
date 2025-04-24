from collections import defaultdict
class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        
        distinct = len(set(nums))
        count = 0

        for i in range(len(nums)):
            currSet = set()
            for j in range(i, len(nums)):
                
                currSet.add(nums[j])
                if len(currSet) == distinct:
                    count += 1
        
        return count








            

        