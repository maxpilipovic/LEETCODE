class Solution:
    def checkPowersOfThree(self, n: int) -> bool:

        def recursive(n):

            if n == 1:
                return True
            
            if n % 3 == 2:
                return False


            return recursive(n // 3)

        
        return recursive(n)
        