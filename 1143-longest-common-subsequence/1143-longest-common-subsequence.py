class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:

        dp = {}

        def backtrack(i, j):

            #Base Case
            if i >= len(text1) or j >= len(text2):
                return 0
            
            if (i, j) in dp:
                return dp[(i, j)]
            
            if text1[i] == text2[j]:
                result = 1 + backtrack(i + 1, j + 1)
            else:
                result = max(backtrack(i + 1, j), backtrack(i, j + 1))

            dp[(i, j)] = result
            return result
        
        return backtrack(0, 0)
        