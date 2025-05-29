class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        
        res = []

        def backtrack(i, curr, num):

            #Base Case
            if len(curr) == k and sum(curr) == n:
                res.append(curr.copy())
                return
            

            if sum(curr) > n:
                return

            if i > 9:
                return

            curr.append(i)
            backtrack(i + 1, curr, num)

            curr.pop()
            backtrack(i + 1, curr, num)
            
            
            
        
        backtrack(1, [], n)

        return res
