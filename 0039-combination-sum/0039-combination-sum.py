class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        
        res = []

        def backtrack(start,  currSum, curr):

            #Base Case
            if currSum == target:
                res.append(curr.copy())
                return 
            
            #currSUm > target. RETURN. THIS DOES NOT WORK. 
            if currSum > target:
                return

            #Recursive backtracking..
            for i in range(start, len(candidates)):
                curr.append(candidates[i])

                #Call our function to backtrack
                backtrack(i, currSum + candidates[i], curr)

                #Backtrack...
                curr.pop()
        

        backtrack(0, 0, [])

        return res