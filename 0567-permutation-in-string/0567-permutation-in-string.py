class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:

        if len(s1) > len(s2):
            return False

        s1_dict = dict()
        s2_dict = dict()

        for char in range(len(s1)):
            s1_dict[s1[char]] = 1 + s1_dict.get(s1[char], 0)
            s2_dict[s2[char]] = 1 + s2_dict.get(s2[char], 0)
        
        #check if they are the same, after first two elements
        if s1_dict == s2_dict:
            return True

        #sliding window part
        left = 0

        for right in range(len(s1), len(s2)):
            #adds 1 to the value of s2[right], default value 0 if not present
            s2_dict[s2[right]] = 1 + s2_dict.get(s2[right], 0)
            #remove left
            del s2_dict[s2[left]]

            #increment left
            left += 1

            #check if they are the same
            if s1_dict == s2_dict:
                return True
        
        return False







        