class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:

        res = 0
        my_dict = Counter(chars)

        for word in words:
            
            currWord = Counter(word)

            wordExists = True
            for char in word:
                if currWord[char] > my_dict.get(char, 0):
                    wordExists = False
                    break
            
            res += len(word) if wordExists == True else 0

        return res
                    

            
                
        

        

        