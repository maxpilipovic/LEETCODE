class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        
        res = []
        stack = []
        stack.append([0, []])

        while stack:

            index, listNums = stack.pop()
            res.append(listNums)

            for i in range(index, len(nums)):

                stack.append((i + 1, listNums + [nums[i]]))

        return res