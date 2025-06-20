class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        if not nums:
            return []

        res = []
        flag = [False] * len(nums)

        def backtrack(flag, curr):
            
            #Base Case
            if len(curr) == len(nums):
                #Append?
                res.append(curr.copy())
                return
            
            for num in range(len(nums)):
                if flag[num] == False:
                    flag[num] = True
                    curr.append(nums[num])
                    backtrack(flag, curr)
                    curr.pop()
                    flag[num] = False

        
        backtrack(flag, [])

        return res
            