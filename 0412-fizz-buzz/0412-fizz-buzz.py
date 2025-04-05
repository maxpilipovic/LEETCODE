class Solution:
    def fizzBuzz(self, n: int) -> List[str]:

        i = 1
        res = []
        while i <= n:
            
            if i % 3 == 0 and i % 5 == 0:
                res.append("FizzBuzz")
            elif i % 3 == 0:
                res.append("Fizz")
            elif i % 5 == 0:
                res.append("Buzz")
            else:
                res.append(str(i))

            i += 1
        return res