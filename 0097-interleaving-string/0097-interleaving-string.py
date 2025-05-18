class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        
        #Base Case
        if len(s1) + len(s2) != len(s3):
            return False
        
        dp = {}

        def backtrack(i1, i2):

            #Base Case
            if i1 + i2 >= len(s3):
                return True
            
            #Memo
            if (i1, i2) in dp:
                return dp[(i1, i2)]

            if i1 < len(s1) and i2 < len(s2) and s1[i1] == s3[i1 + i2] and s2[i2] != s3[i1 + i2]:
                #Do something
                x1 = backtrack(i1 + 1, i2)
                dp[(i1, i2)] = x1
                return dp[(i1, i2)]
            elif i1 < len(s1) and i2 < len(s2) and s1[i1] != s3[i1 + i2] and s2[i2] == s3[i1 + i2]:
                #Do something
                x2 = backtrack(i1, i2 + 1)
                dp[(i1, i2)] = x2
                return dp[(i1, i2)]
            elif i1 < len(s1) and i2 < len(s2) and s1[i1] != s3[i1 +i2] and s2[i2] != s3[i1 + i2]:
                return False
            else:
                #We have two decisions
                option1 = (i1 < len(s1) and s1[i1] == s3[i1 + i2] and backtrack(i1 + 1, i2))
                option2 = (i2 < len(s2) and s2[i2] == s3[i1 + i2] and backtrack(i1, i2 + 1))
                dp[(i1, i2)] = option1 or option2
                return dp[(i1, i2)]

        
        return backtrack(0, 0)
            