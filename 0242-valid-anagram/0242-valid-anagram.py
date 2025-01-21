class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        if len(s) > len(t):
            return False
        my_dict = dict()

        for i in range(len(s)):
            if s[i] in my_dict:
                my_dict[s[i]] += 1
            else:
                my_dict[s[i]] = 1

        for i in range(len(t)):
            if t[i] in my_dict:
                my_dict[s[i]] -= 1
            else:
                return False
        
        return True

        