class Solution:
    def minimumLevels(self, possible: List[int]) -> int:
        
        #Change everything into -1
        for i in range(len(possible)):
            if possible[i] == 0:
                possible[i] = -1

        #prefixDiff = 0
        totalSum = sum(possible)
        num = 1
        sumAlice = 0
        while num < len(possible):
            
            #Prefix Sum
            #Slice
            #alicePart = possible[:num]
            sumAlice += possible[num - 1] #Prefixsum
            sumBob = totalSum - sumAlice
            

            #Sum
            #sumAlice = sum(alicePart)
            #sumBob = sum(bobPart)

            if sumAlice > sumBob:
                return num
        
            num += 1
        
        return -1