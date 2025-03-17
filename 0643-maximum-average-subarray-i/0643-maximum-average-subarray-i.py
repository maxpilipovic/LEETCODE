class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        
        left = 0
        currWindow = sum(nums[:k])
        res = currWindow

        for right in range(k, len(nums)):

            currWindow += nums[right] - nums[left]
            res = max(res, currWindow)
            left += 1

            

        return res / k
                
                
                        

        