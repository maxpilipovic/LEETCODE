class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:

        res = []
        curr = []

        candidates.sort()

        def backtrack(i, total):

            #Base Case - Checking the total equals target (valid combination)
            if total == target:
                res.append(curr.copy())
                return
            
            #Base Case - Checking the total and the length
            if total > target or i >= len(candidates):
                return

            
            #Recursive Case
            #Add, backtrack, pop
            curr.append(candidates[i])
            backtrack(i + 1, total + candidates[i])
            curr.pop()

            #Handle the duplicates - (Bounds, check adjacesent number)
            while i + 1 < len(candidates) and candidates[i] == candidates[i + 1]:
                i += 1
            
            backtrack(i + 1, total)

        backtrack(0, 0)
        return res




        