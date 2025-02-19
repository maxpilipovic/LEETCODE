class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        res = []
        array = ["a", "b", "c"]


        def backtrack(curr):
            #Base Case
            if len(curr) == n:
                res.append(curr)
                return 
            
            #Recursive Case
            for char in array:
                #We check if curr is empty (If its empty we dont need to check the adjacesent). 
                if not curr or char != curr[-1]:
                    backtrack(curr + char)



        
        backtrack("")

        return res[k - 1] if k <= len(res) else ""

        