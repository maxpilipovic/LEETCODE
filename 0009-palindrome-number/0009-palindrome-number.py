class Solution:
    def isPalindrome(self, x: int) -> bool:
        
        #Two pointers?

        xList = list(str(x))

        left = 0
        right = len(xList) - 1

        while left < right:

            if xList[left] != xList[right]:
                return False

            left += 1
            right -= 1
        return True
        print(xList)


