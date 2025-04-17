class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:

        res = []
        nums.sort() #Sorting handles duplicates

        def backtrack(index, curr):
            
            #Base Case
            if index == len(nums):
                if curr not in res:
                    res.append(curr.copy())

            #Recursive

            if index < len(nums):
                curr.append(nums[index])
                backtrack(index + 1, curr)
                curr.pop()
                backtrack(index + 1, curr)

        backtrack(0, [])

        return res

