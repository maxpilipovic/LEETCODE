class Solution:
    def minimumIndex(self, nums: List[int]) -> int:

        my_dict = Counter(nums)

        #Find our most frequent element
        freqKey = None
        freqVal = -float('inf')
        for key in my_dict.keys():
            if my_dict[key] > freqVal:
                freqVal = my_dict[key]
                freqKey = key

        return self.checkFreqSub(freqKey, freqVal, nums)

    def checkFreqSub(self, key, val, nums):
        leftCount = 0
        rightCount = val

        for i in range(len(nums)):
            if nums[i] == key:
                leftCount += 1
                rightCount -= 1
        
            leftSize = i + 1
            rightSize = len(nums) - leftSize 

            if leftCount > leftSize // 2 and rightCount > rightSize // 2:
                return i 
            
        return -1 #Did not find



        