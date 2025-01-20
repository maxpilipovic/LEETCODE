class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        
        curr = []
        res = []
        length = len(candidates)

        #Sort (Avoids duplicates)
        candidates.sort()

        def backtrack(start):

            #Base case
            current_sum = sum(curr)
            
            #Stop unessecary recursion
            if current_sum > target:
                return

            #Check if equal to target
            if current_sum == target:
                res.append(curr.copy())
                return
            
            #Recursive case
            for j in range(start, length):
                
                #Append
                curr.append(candidates[j])

                #Backtrack
                backtrack(j)

                #Pop
                curr.pop()
            
        backtrack(0)

        return res