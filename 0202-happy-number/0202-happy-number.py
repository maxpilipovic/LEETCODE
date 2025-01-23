class Solution:
    def isHappy(self, n: int) -> bool:
        
        seen = set()

        while n != 1:
            #If we see a cycle
            if n in seen:
                return False
            seen.add(n)

            #Calculate digit^2 for each digit in str(n)
            n = sum(int(digit) ** 2 for digit in str(n))
            
        return True

        
        

        