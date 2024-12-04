class Solution:
    def fizzBuzz(self, n: int) -> List[str]:

        array = []

        count = 1
        while count <= n:

            if count % 3 == 0 and count % 5 == 0:
                array.append("FizzBuzz")
            elif count %3 == 0:
                array.append("Fizz")
            elif count % 5 == 0:
                array.append("Buzz")
            else:
                array.append(str(count))
            count += 1
        return array
        