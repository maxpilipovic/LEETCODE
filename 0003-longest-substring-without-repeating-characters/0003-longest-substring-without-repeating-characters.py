class Solution(object):
    def lengthOfLongestSubstring(self, s):

        hashy = set()
        left = 0
        max_length = 0

        for right in range(len(s)):

            while s[right] in hashy:
                hashy.remove(s[left])
                left += 1
        
            hashy.add(s[right])
            max_length = max(max_length, right - left + 1)
        
        return max_length


        