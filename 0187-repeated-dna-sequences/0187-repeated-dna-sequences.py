class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:

        hashy = set()
        res = set()
        left = 0

        for right in range(len(s)):

            if (right - left + 1) == 10:
                subString = s[left:right + 1]

                if str(subString) in hashy:
                    res.add(str(subString))
                else:
                    hashy.add(str(subString))

                left += 1
        return list(res)