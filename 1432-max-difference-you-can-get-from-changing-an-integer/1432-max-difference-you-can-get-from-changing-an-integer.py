class Solution:
    def maxDiff(self, num: int) -> int:
        
        strNum = str(num)

        #Max
        maxNum = None
        for char in strNum:
            if char != '9':
                maxNum = char
                break
        
        #Replace all the instances with '9'
        if maxNum:
            strMaxNum = strNum.replace(maxNum, '9')
        else:
            strMaxNum = strNum

        print(strMaxNum)

        #Min
        minNum = None
        for index, char in enumerate(strNum):

            if index == 0 and char != '1':
                minNum = char
                strMinNum = strNum.replace(minNum, '1')
                break
            elif index > 0 and char != '1' and char != '0':
                minNum = char
                strMinNum = strNum.replace(minNum, '0')
                break

        #Remove the leading zero's???
        if not minNum:
            strMinNum = strNum

        return int(strMaxNum) - int(strMinNum)
