class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:

        res = []
        flag = False

        #Check first value
        #0 is True
        #1 is False

        if groups[0] == 0:
            flag = False
            res.append(words[0])
        else:
            flag = True
            res.append(words[0])

        for i in range(1, len(words)):
            if groups[i] == 0 and flag == False:
                continue
            elif groups[i] == 1 and flag == False:
                flag = True
                res.append(words[i])
            elif groups[i] == 1 and flag == True:
                continue
            else:
                flag = False
                res.append(words[i])
        
        return res

        