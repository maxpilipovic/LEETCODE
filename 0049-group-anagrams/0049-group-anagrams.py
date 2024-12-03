class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        #create dict
        my_dict = dict()


        for i in strs:
            sorted_word = ''.join(sorted(i))
            if sorted_word in my_dict:
                #add to list
                my_dict[sorted_word].append(i)
            else:
                my_dict[sorted_word] = [i]
        
        return list(my_dict.values())

        