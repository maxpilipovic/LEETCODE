class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        
        if len(s) != len(t):
            return False
        
        if s == t:
            return True

        my_dict = dict()

        for i in range(len(s)):
            if s[i] not in my_dict:
                for value in my_dict.values():
                    if value in my_dict:
                        return False
                my_dict[s[i]] = t[i]
            else:
                if my_dict[s[i]] != t[i]:
                    return False
        
        return True
            



        