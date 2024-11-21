class Solution:
    def addBinary(self, a: str, b: str) -> str:

        num1 = int(a, 2)
        num2 = int(b, 2)

        total = num1 + num2

        res = bin(total)[2:]

        return res
        