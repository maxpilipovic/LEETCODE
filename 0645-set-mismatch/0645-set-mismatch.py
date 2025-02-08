class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        
        nums.sort()
        res = []
        hashy = set()
        number1 = 0

        #Loop over nums to use hashy to find duplicated number
        for i in nums:
            if i in hashy:
                number1 = i
            hashy.add(i)
        
        number2 = number1 + 1

        return [number1, number2]
        

