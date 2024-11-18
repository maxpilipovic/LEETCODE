class Solution:
    def numSteps(self, s: str) -> int:
        numStr = str(s)
        num = int(numStr, 2)

        count = 0
        while num != 1:

            if (num % 2 == 0):
                num = num // 2
                count += 1
            
            else:
                num = num + 1
                count += 1
        
        return count
            


        