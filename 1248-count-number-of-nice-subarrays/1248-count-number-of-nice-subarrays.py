class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        
        left = 0
        oddNums = 0
        count = 0
        prefixEven = 0

        for right in range(len(nums)):

            if nums[right] % 2 != 0:
                #Odd
                oddNums += 1
                prefixEven = 0

            while oddNums >= k:

                if nums[left] % 2 != 0:
                    oddNums -= 1
                
                prefixEven += 1
                left += 1

            count += prefixEven

        return count

            
