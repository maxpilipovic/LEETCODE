class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        
        res = ''

        for i in range(len(s)):
            for j in range(i + 1, len(s) + 1):
                slice = s[i:j]

                if (self.checkSubstring(slice)) == True:
                    if len(slice) > len(res):
                        res = slice

        return res

    def checkSubstring(self, slice: str) -> bool:
        hashy = set(slice)
        
        for char in hashy:
            if char.swapcase() not in hashy:
                return False
        return True





                