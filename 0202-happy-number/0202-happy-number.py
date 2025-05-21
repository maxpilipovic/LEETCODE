class Solution:
    def isHappy(self, n: int) -> bool:
        
        seen = set()

        def recursion(num):

            temp = 0

            if num == 1:
                return True
            
            if num in seen:
                return False

            seen.add(num)
            
            for digit in str(num):
                temp += int(digit) ** 2
            
            return recursion(temp)

        return recursion(str(n))