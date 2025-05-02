class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        
        dp = {}

        setWordDict = set(wordDict)

        def checkSubString(substring):

            if substring in setWordDict:
                return True
            else:
                return False

        def recursion(i):

            #Base
            if i == len(s):
                return True
            
            if i in dp:
                return dp[i]

            for j in range(i + 1, len(s) + 1):

                subString = s[i:j]
                if checkSubString(subString):
                    #Do something
                    if recursion(j):
                        dp[j] = True
                        return True
                        
            dp[i] = False
            
            return False

        return recursion(0)

        
        