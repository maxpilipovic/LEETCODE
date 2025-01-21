class Solution:
    def reverseVowels(self, s: str) -> str:

        hashy = set("aeiouAEIOU")
        s = list(s)
        left = 0
        right = len(s) - 1

        while left < right:
            if s[left] not in hashy:
                left += 1
            if s[right] not in hashy:
                right -= 1

            if s[right] in hashy and s[left] in hashy:
                s[left], s[right] = s[right], s[left]
                left += 1
                right -= 1
        
        return "".join(s)





        