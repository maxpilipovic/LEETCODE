class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        
        dp = {}

        def backtrack(i, j):

            #Base Case
            if i >= len(word1):
                return len(word2) - j 
            if j >= len(word2):
                return len(word1) - i
            
            #Dp part
            if (i, j) in dp:
                return dp[(i, j)]

            #3 States Insert, Delete, Replace
            if word1[i] == word2[j]:
                ans = backtrack(i + 1, j + 1)
            else:
                #Insert
                insert = 1 + backtrack(i, j + 1)
                delete = 1 + backtrack(i + 1, j)
                replace = 1 + backtrack(i + 1, j + 1)
                ans = min(insert, delete, replace)

            dp[(i, j)] = ans
            
            return ans
        
        return backtrack(0, 0)

