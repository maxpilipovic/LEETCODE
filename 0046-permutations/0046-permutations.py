class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        res = []

        def backtrack(curr):

            #Base Case
            if len(curr) == len(nums):
                res.append(curr.copy())
                return

            #Recursive Case
            for i in range(len(nums)):

                if nums[i] in curr:
                    continue

                curr.append(nums[i])
                backtrack(curr)
                curr.pop()



        backtrack([])
        return res