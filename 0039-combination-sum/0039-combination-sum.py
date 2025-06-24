class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        

        res = []

        def backtrack(i, curr, total):

            #Base Case
            if total == target:
                res.append(curr.copy())
                return

            if i >= len(candidates) or total > target:
                return
            
            #Recursive
            curr.append(candidates[i])
            backtrack(i, curr, total + candidates[i])

            #backtrack
            curr.pop()
            backtrack(i + 1, curr, total)

        
        backtrack(0, [], 0)

        return res