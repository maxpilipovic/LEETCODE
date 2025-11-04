class Solution:
    def fib(self, n: int) -> int:
        
        #Base Case
        if n == 0 or n == 1:
            return n
        
        #Recursive Case
        return self.fib(n-1) + self.fib(n-2)