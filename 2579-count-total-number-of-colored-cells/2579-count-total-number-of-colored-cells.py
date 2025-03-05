class Solution:
    def coloredCells(self, n: int) -> int:
        
        i = 1
        res = 1

        while i < n:
            curr = 4 * i
            res += curr
            i += 1
        
        return res
            

        