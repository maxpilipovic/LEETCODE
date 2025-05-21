class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        
        #Extra Space
        n = len(matrix)
        newMatrix = [[0] * n for _ in range(n)]
        print(newMatrix)

        rows = len(matrix)
        cols = len(matrix)

        print(rows)
        print(cols)

        for row in range(rows):
            for col in range(cols):
                newMatrix [col][n - 1 - row] = matrix[row][col]
        
        for row in range(rows):
            for col in range(cols):
                matrix[row][col] = newMatrix[row][col]
        
        return matrix
        