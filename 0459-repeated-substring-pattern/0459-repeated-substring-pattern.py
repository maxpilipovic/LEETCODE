class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        
        #1
        #No Hashmap
        #Start half way. 

        doubleS = s + s
        trimmed = doubleS[1:-1]

        for i in range(len(trimmed) - len(s) + 1):
            if trimmed[i:i + len(s)] == s:
                return True
        
        return False
            






