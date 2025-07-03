class Solution:
    def kthCharacter(self, k: int) -> str:
        
        originalWord = "a"

        while len(originalWord) < k:
            newWord = ""

            for i in range(len(originalWord)):
                offset = (ord(originalWord[i]) - ord('a') + 1) % 26
                newchar = chr(ord('a') + offset)

                newWord += newchar
            
            originalWord += newWord
        
        return originalWord[k - 1]
        






            