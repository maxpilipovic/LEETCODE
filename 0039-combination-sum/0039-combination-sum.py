class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:

        res = []

        def backtrack(start, currSum, curr):
            #Base Case
            if currSum == target:
                res.append(curr.copy())
                return
                
            if currSum > target:
                return

            for i in range(start, len(candidates)):

                curr.append(candidates[i])
                backtrack(i, currSum + candidates[i], curr)
                curr.pop()
            
        backtrack(0, 0, [])

        return res