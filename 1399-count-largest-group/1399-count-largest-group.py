class Solution:
    def countLargestGroup(self, n: int) -> int:
        my_dict = {}
        largestSum = 0
        count = 0

        for num in range(1, n + 1):

            #Calculated digitSum
            digitSum = sum([int(digit) for digit in str(num)])
            
            if digitSum not in my_dict:
                my_dict[digitSum] = 1
            else:
                my_dict[digitSum] += 1
            

        maxVal = 0
        count = 0    
        #Count values and return max
        for value in my_dict.values():

            if value == maxVal:
                count += 1
            elif value > maxVal:
                maxVal = value
                count = 1
        
        print(my_dict)
        print(maxVal)
        return count
            