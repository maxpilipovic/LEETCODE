class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        
        hashy = set()
        left = 0

        for right in range(len(s)):

            if right - left + 1 == k:

                subStr = s[left:right + 1]
                hashy.add(subStr)
                left += 1
        
        if len(hashy) == 2 ** k:
            return True
        
        return False



