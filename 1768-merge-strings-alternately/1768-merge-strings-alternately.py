class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:

        res = []
        left = 0
        right = 0

        while left < len(word1) and right < len(word2):
            
            res.append(word1[left])
            left += 1
            
            res.append(word2[right])
            right += 1
        
        if left < len(word1):
            #append the rest to res
            res.extend(word1[left:])
        
        if right < len(word2):
            #append the rest to res
            res.extend(word2[right:])

        return "".join(res)




        