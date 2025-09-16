class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        maxNum = 0
        left = 0
        hashy = set() #To hold numbers of window

        for right in range(len(s)):

            while s[right] in hashy:
                hashy.remove(s[left])
                left += 1
        
            hashy.add(s[right])
            maxNum = max(maxNum, len(hashy))
        
        return maxNum


        