class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        my_dict = dict()
        maxLength = 0
        left = 0


        #Solving using index's
        for right in range(len(s)):

            #If in dictionary
            if s[right] in my_dict and my_dict[s[right]] >= left:

                #Move our left pointer to the right of last occurence
                left = my_dict[s[right]] + 1

            #Update char's last seen index
            my_dict[s[right]] = right

            #Update our maxLength
            maxLength = max(maxLength, right - left + 1)

        return maxLength

        



        