class Solution(object):
    def characterReplacement(self, s, k):
        
        my_dict = dict()
        left = 0
        max_length = 0 
        max_freq = 0

        for right in range(len(s)):
            if s[right] in my_dict:
                my_dict[s[right]] += 1 
            else:
                my_dict[s[right]] = 1

            max_freq = max(max_freq, my_dict[s[right]])

            if (right - left + 1) - max_freq > k:

                my_dict[s[left]] -= 1
                left += 1

            max_length = max(max_length, right - left + 1)

        return max_length

            




        