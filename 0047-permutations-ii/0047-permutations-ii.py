class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        
        nums.sort()
        res = []
        used = [False] * len(nums)

        def backtrack(curr):

            #Base Case
            if len(curr) == len(nums):
                res.append(curr.copy())
                return
            
            #Recursive
            for i in range(len(nums)):

                if used[i]:
                    continue
                
                #Skip duplicates
                if i > 0 and nums[i] == nums[i - 1] and not used [i - 1]:
                    continue
                
                used[i] = True
                curr.append(nums[i])
                backtrack(curr)
                curr.pop()
                used[i] = False
            

        
        backtrack([])
        return res

            
