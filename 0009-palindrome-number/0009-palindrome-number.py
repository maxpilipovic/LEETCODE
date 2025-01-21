class Solution:
    def isPalindrome(self, x: int) -> bool:

        left = 0
        s = list(str(x))
        right = len(s) - 1

        while left < right:
            if s[right] == s[left]:
                left += 1
                right -= 1
            else:
                return False

        return True

        