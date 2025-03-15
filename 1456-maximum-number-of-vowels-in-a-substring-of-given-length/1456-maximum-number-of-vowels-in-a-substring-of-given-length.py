class Solution:
    def maxVowels(self, s: str, k: int) -> int:

        hashy = {'a', 'e', 'i', 'o', 'u'}
        nums = list(s)
        res = 0
        left = 0
        count = 0
        for right in range(len(nums)):

            if nums[right] in hashy:
                count += 1
            
            if (right - left + 1) == k:

                res = max(res, count)
                if nums[left] in hashy:

                    #Removing techinically
                    count -= 1
                
                left += 1
    

        return res
            




