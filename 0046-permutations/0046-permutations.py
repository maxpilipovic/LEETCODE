class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        res = []
        curr = []

        def backtrack():

            #Base Case
            if len(nums) == len(curr):
                res.append(curr.copy())
                return
            
            #Recursive Case
            for i in range(len(nums)):
                if nums[i] in curr:
                    continue
                curr.append(nums[i])
                backtrack()
                curr.pop()
        
        backtrack()
        return res

        