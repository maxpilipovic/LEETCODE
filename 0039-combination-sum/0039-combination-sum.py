class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        
        res = []


        def backtrack(index, curr):

            #Base Case
            if sum(curr) > target:
                return

            if sum(curr) == target:
                res.append(curr.copy())
                return
            
            #Recursive Case
            if index <= len(candidates) - 1:
                curr.append(candidates[index])
                backtrack(index, curr)
            
                curr.pop()
                backtrack(index + 1, curr)

        


        backtrack(0, [])

        return res