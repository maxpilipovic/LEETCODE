class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        
        my_dict = dict()

        for i in range(len(strs)):
            sorted_word = ''.join(sorted(strs[i]))

            if sorted_word in my_dict:
                my_dict[sorted_word].append(strs[i])
            else:
                my_dict[sorted_word] = [strs[i]]
        
        print(my_dict)
        return list(my_dict.values()) 
        