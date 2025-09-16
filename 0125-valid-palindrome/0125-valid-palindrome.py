class Solution:
    def isPalindrome(self, s: str) -> bool:

        def clean(text: str) -> str:
            return "".join(ch.lower() for ch in text if ch.isalnum())

        s = clean(s)
        left, right = 0, len(s) - 1

        while left < right:
            if s[left] != s[right]:
                return False
            left += 1
            right -= 1

        return True