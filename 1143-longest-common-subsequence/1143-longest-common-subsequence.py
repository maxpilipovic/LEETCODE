class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        #MEMOIZATION SOLUTION

        memo = {}

        def recursion(i, j):

            #Base Case
            if i == len(text1) or j == len(text2):
                return 0
            
            #Check result in memo
            if (i, j) in memo:
                return memo[(i, j)]
            
            if text1[i] == text2[j]:
                result = 1 + recursion(i + 1, j + 1)
            else:
                result = max(recursion(i + 1, j), recursion(i, j + 1))

            memo[(i, j)] = result
            return result

        return recursion(0, 0)

