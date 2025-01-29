class Solution:
    def longestPalindrome(self, s: str) -> str:

        #Check if empty
        if not s:
            return ""
        
        #Sliding window from center, until invalid.
        def window(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            #Slicing return, [left + 1 -> right] (THE WINDOW)
            return s[left + 1:right]

        longest = ""
        for i in range(len(s)):
            #Check even
            odd = window(i, i)
            #Check odd
            even = window(i, i+1)

            #Check the lengths
            if len(even) > len(longest):
                longest = even
            if len(odd) > len(longest):
                longest = odd

        return longest
        



        