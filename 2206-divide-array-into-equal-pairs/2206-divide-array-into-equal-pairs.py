class Solution:
    def divideArray(self, nums: List[int]) -> bool:

        #Create our hashmap and populate it
        my_dict = dict()

        for i in range(len(nums)):
            if nums[i] in my_dict:
                my_dict[nums[i]] += 1
            else:
                my_dict[nums[i]] = 1
        
        #Find how many pairs
        length = len(nums) // 2

        for key, value in my_dict.items():
            while value >= 2:
                value -= 2
                length -= 1
        
        return True if length == 0 else False


        