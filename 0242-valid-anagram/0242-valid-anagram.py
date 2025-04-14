class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        my_dict = {}

        for i in s:
            if i not in my_dict:
                my_dict[i] = 1
            else:
                my_dict[i] += 1
        
        for i in t:
            if i not in my_dict:
                return False
            else:
                my_dict[i] -= 1
        

        return all(count == 0 for count in my_dict.values()) #Return true if the statement is true, else false... ALWAYS TRUE