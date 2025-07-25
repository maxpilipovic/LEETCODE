class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        
        n = len(colsum)
        row1 = [0] * len(colsum)
        row2 = [0] * len(colsum)

        for i in range(n):

            if colsum[i] == 2:
                upper -= 1
                lower -= 1
                row1[i] = 1
                row2[i] = 1
            elif colsum[i] == 1:
                if upper >= lower:
                    upper -= 1
                    row1[i] += 1
                else:
                    lower -= 1
                    row2[i] += 1

        if upper != 0 or lower != 0:
            return []
            
        return [row1, row2]
