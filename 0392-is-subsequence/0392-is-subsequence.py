class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        
        if not s:
            return True

        
        left = 0
        count = 0

        for right in range(len(t)):

            if s[left] == t[right]:
                count += 1
                left += 1
                print(count)

                if left == len(s):
                    return True
        
        return True if count == len(s) else False