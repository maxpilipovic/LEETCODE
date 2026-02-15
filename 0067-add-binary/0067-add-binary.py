class Solution:
    def addBinary(self, a: str, b: str) -> str:
        
        i = len(a) - 1
        j = len(b) - 1
        carry = 0
        resStr = ""
        
        while i >= 0 or j >= 0 or carry:
            #Convert int
            #2. Bounds check?

            if i < 0:
                bitA = 0
            else:
                bitA = int(a[i])

            if j < 0:
                bitB = 0
            else:
                bitB = int(b[j])
            
            #0, 1, 2, 3
            total = bitA + bitB + carry

            if total == 0:
                resStr += str(total)
                carry = 0
            elif total == 1:
                resStr += str(total)
                carry = 0
            elif total == 2:
                resStr += str(0)
                carry = 1
            elif total == 3:
                resStr += str(1)
                carry = 1

            i -= 1
            j -= 1

        return resStr[::-1]
        







