from collections import Counter
class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:

        digitCounter = Counter(digits)
        res = []

        def checkNumbers(num):
            
            currCounter = Counter(int(d) for d in numStr)

            for key, value in currCounter.items():
                if digitCounter[key] < value:
                    return False

            return True

        for num in range(100, 1000):
            if num % 2 == 0:
                numStr = str(num)

                if checkNumbers(numStr):
                    res.append(num)
        
        return res

            