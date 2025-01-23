class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:

        res = []
        curr = []

        def backtrack(i):

            #Base case
            if i >= len(nums):
                res.append(curr.copy())
                return

            #Recursive case

            #Keep and backtrack
            curr.append(nums[i])
            backtrack(i + 1)

            #Remove and backtrack
            curr.pop()
            backtrack(i + 1)
            
        backtrack(0)

        return res



        