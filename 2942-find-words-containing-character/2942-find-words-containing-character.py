class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:

        flag = False
        res = []

        for index, word in enumerate(words):
            for i in word:
                if i == x:
                    flag = True
                    print(i)
            
            if flag == True:
                res.append(index)
                flag = False
        
        return res


        