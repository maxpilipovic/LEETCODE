class Solution:
    def minMaxDifference(self, num: int) -> int:

        numStr = list(str(num))


        #Find our max
        maxTarget = None
        for num in numStr:
            if num != '9':
                maxTarget = num
                break

        maxList = numStr.copy()
        #Flip
        for i in range(len(maxList)):
            if maxList[i] == maxTarget:
                maxList[i] = '9'

        #Find our min
        minTarget = None
        for num in numStr:
            if num != '0':
                minTarget = num
                break
        
        minList = numStr.copy()
        #Flip
        for i in range(len(minList)):
            if minList[i] == minTarget:
                minList[i] = '0'

        #Remove the zeros
        while minList and minList[0] == '0':
            del minList[0]
        
        print(maxList)
        print(minList)

        resMax = int("".join(maxList))
        resMin = int("".join(minList)) if minList else 0

        return resMax - resMin



            

        