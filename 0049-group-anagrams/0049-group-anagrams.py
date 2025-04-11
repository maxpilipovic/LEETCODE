class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        my_dict = {}
        res = []

        for word in strs:
            listWord = list(word)
            listWord.sort()
            
            sortedWord = "".join(listWord)
            print(sortedWord)

            if sortedWord not in my_dict:
                my_dict[sortedWord] = []
                my_dict[sortedWord].append(word)
            else:
                my_dict[sortedWord].append(word)
        
        for value in my_dict.values():
            res.append(value)
    
        return res
