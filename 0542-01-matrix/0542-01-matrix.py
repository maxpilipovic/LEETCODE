from collections import deque
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        
        #USE VISITED SET!!!
        
        rows = len(mat)
        cols = len(mat[0])
        directions = [(0,-1), (0, 1), (1, 0), (-1, 0)] #Up, Down, Right, Left
        visited = set()

        #List comprehension (Makes each cell -1) We make every 0 -> 0. Others -1 -> 1
        res = [[-1 for _ in range(cols)] for _ in range(rows)]
        #Create queue
        queue = deque()

        for row in range(rows):
            for col in range(cols):
                if mat[row][col] == 0:
                    res[row][col] = 0
                    queue.append((row, col))
        
        #BFS
        while queue:
            row, col = queue.popleft()

            for nr, nc in directions:
                newRow = nr + row
                newCol = nc + col

                if 0 <= newRow < rows and 0 <= newCol < cols and res[newRow][newCol] == -1: #-1 means not visited
                    res[newRow][newCol] = res[row][col] + 1
                    queue.append((newRow, newCol))
        
        return res

