class Solution:
    def countSubstrings(self, s: str) -> int:

        dp = [[False] * len(s) for _ in range(len(s))]
        count = 0

        for i in range(len(s)):
            for j in range(i + 1):

                if s[i] == s[j] and (i - j < 2 or dp[j+1][i-1]):
                    dp[j][i] = True
                    count += 1
        
        return count





        