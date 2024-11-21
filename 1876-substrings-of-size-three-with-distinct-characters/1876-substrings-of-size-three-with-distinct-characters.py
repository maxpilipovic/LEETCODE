class Solution:
    def countGoodSubstrings(self, s: str) -> int:

        left = 0
        arrayNums = []
        count = 0

        for right in range(len(s)):
            arrayNums.append(s[right])

            if len(arrayNums) == 3:
                if self.checkSub(arrayNums):
                    count += 1

                arrayNums.pop(0)
                left += 1

        return count

    def checkSub(self, arrayNums) -> bool:
        hashy = set(arrayNums)

        return len(hashy) == len(arrayNums)
        

        


        