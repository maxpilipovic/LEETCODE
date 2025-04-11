class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        
        if not nums:
            return []
            
        res = []
        slow = 0
        
        for fast in range(1, len(nums)):
        
            if nums[fast] != nums[fast - 1] + 1: #If not consectutive
                
                if slow == fast - 1: #If range is just one number
                    res.append(str(nums[slow]))

                else: #If range is a range
                    res.append(f"{nums[slow]}->{nums[fast - 1]}")
            
                slow = fast

        #Append last character (edge case)
        if slow == len(nums) - 1:
            res.append(str(nums[slow]))
        else:
            res.append(f"{nums[slow]}->{nums[len(nums) - 1]}")  

        return res

        