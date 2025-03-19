class Solution:
    def minOperations(self, nums: List[int]) -> int:

        #Greedy
        k = 3
        left = 0
        res = 0
        
        def flip(nums, j):
            if nums[j] == 1:
                nums[j] = 0
            else:
                nums[j] = 1



        for i in range(len(nums)):
            
            #Perform the flips
            if nums[i] == 0:

                if i + k > len(nums): #Out of bounds
                    return -1
                
                for j in range(i, i + k): #Window size
                    flip(nums, j)
                
                res += 1
        

        return res




        