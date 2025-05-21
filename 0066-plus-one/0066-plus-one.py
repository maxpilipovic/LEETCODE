class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        
        digit = ""
        print(digits)

        for i in digits:
            digit += str(i)
        
        digitVal = int(digit) + 1
        print(digitVal)

        res = []
        for i in str(digitVal):
            res.append(int(i))
        
        return res

        