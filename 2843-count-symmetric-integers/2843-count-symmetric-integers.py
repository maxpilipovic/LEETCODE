class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        
        start = low
        count = 0

        while start <= high:
            strNum = str(start)
            length = len(strNum)

            if length % 2 == 0:
                half = length // 2

                #Slice two halves and check if they are equal.
                firstHalf = strNum[:half]
                secondHalf = strNum[half:]

                sum1 = 0
                sum2 = 0

                for i in firstHalf:
                    sum1 += int(i)
                for i in secondHalf:
                    sum2 += int(i)

                if sum1 == sum2:
                    count += 1
            
            start += 1
        
        return count