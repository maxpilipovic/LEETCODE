class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        my_dict = {}

        #s = anagram -> a n a g r a m

        # a : 3
        # n : 1
        # g : 1
        # m : 1
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
        

        return all(count == 0 for count in my_dict.values()) #Return boolean
        

