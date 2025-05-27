class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        
        num1 = 0
        for i in range(1, n + 1):
            print(i)

            #Divisible by M
            if i % m != 0:
                continue
            num1 += i
        
        num2 = 0
        for i in range(1, n + 1):

            #Not divisible by M
            if i % m == 0:
                continue 
            
            num2 += i

        return num2 - num1

