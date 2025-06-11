class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        
        #Get the length of bigNum
        bigNum = max(a, b, c)
        bigNum = len(bin(bigNum)[2:])


        one = bin(a)[2:].zfill(bigNum)
        two = bin(b)[2:].zfill(bigNum)
        three = bin(c)[2:].zfill(bigNum)
        flips = 0

        print(one)
        print(two)
        print(three)
        
        for i in range(bigNum - 1, -1, -1):

            print(one[i])
            if int(three[i]) == 1:
                if int(one[i]) == 0 and int(two[i]) == 0:
                    flips += 1
            else: #If its 0
                if int(one[i]) == 1:
                    flips += 1
                if int(two[i]) == 1:
                    flips += 1

        return flips