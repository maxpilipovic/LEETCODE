class Solution:
    def hammingWeight(self, n: int) -> int:
        
        #Conver to binary
        binaryNum = bin(n)[2:]

        count = 0
        for i in str(binaryNum):
            if i == '1':
                count += 1
        
        return count