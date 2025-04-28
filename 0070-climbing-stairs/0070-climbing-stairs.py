class Solution:
    def climbStairs(self, n: int) -> int:
        
        count = {}

        def recursive(i):
            
            #Base
            if i == 0:
                return 1
            
            if i < 0:
                return 0

            if i in count:
                return count[i]

            count[i] = recursive(i - 1) + recursive(i - 2)
            

            #Recursive
            return count[i]


        return recursive(n)









        