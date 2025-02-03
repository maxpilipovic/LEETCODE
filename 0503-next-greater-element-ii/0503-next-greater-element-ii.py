class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        
        #For circular array
        newNums = nums * 2

        #Dict
        my_dict = dict()

        #Res array
        res = [-1] * len(nums)

        for i in range(len(nums)):
            for j in range(i + 1, len(newNums)):
                if newNums[j] > newNums[i]:
                    res[i] = newNums[j]
                    break
        
        return res

           

        