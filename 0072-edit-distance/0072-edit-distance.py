class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        
        dp = {}

        def backtrack(i, j):

            #Base Case
            if i == len(word1):
                dp[(i, j)] = len(word2) - j
                return dp[(i, j)]
            
            if j == len(word2):
                dp[(i, j)] = len(word1) - i
                return dp[(i, j)]

            if (i, j) in dp:
                return dp[(i, j)]
            
            if word1[i] == word2[j]:
                #They the same, move.
                dp[(i, j)] = backtrack(i + 1, j + 1)
                return dp[(i, j)]
            else:
                #Insert
                insert = backtrack(i, j + 1)
                #Delete
                delete = backtrack(i + 1, j)
                #Replace
                replace = backtrack(i + 1, j + 1)

                dp[(i, j)] = 1 + min(insert, delete, replace)
                return dp[(i, j)]
                
        return backtrack(0, 0)