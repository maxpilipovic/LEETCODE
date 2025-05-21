class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:

        newMatrix = matrix
        rows = len(matrix)
        cols = len(matrix[0])

        print(rows)
        print(cols)

        #Sets to zero
        zeroRows = set()
        zeroCols = set()

        for row in range(rows):
            for col in range(cols):
                if matrix[row][col] == 0:
                    zeroRows.add(row)
                    zeroCols.add(col)

        for row in range(rows):
            for col in range(cols):
                if row in zeroRows or col in zeroCols:
                    newMatrix[row][col] = 0
        
        return newMatrix



        