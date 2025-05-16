class Solution:
    def countPrimes(self, n: int) -> int:
        
        #Anything less then 2, we know is not a prime. 2 is first prime
        
        if n < 2:
            return 0
        
        primes = [1] * n
        primes[0] = 0
        primes[1] = 0

        for i in range(2, n):
            tmp = i
            
            if primes[i]:
                tmp += i

                while tmp < n:
                    primes[tmp] = 0
                    tmp += i
            

        return sum(primes)
