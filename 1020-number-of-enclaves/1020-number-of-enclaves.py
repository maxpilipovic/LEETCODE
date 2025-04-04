from collections import deque
class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:

        rows = len(grid)
        cols = len(grid[0])
        visited = set()
        queue = deque()
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)] #Left, Right, Up, Down

        #1 Building our queue
        for row in range(rows):
            for col in range(cols):
                
                if (row == 0 or row == rows - 1 or col == 0 or col == cols - 1) and grid[row][col] == 1: #Put them in the queue
                    queue.append((row, col))
                    visited.add((row, col))
        

        #2 Run BFS on the directions
        while queue:
            cRow, cCol = queue.popleft()

            for nRow, nCol in directions:
                newRow = cRow + nRow
                newCol = cCol + nCol 

                #Bounds
                if 0 <= newRow < rows and 0 <= newCol < cols and grid[newRow][newCol] == 1 and (newRow, newCol) not in visited:
                    queue.append((newRow, newCol))
                    visited.add((newRow, newCol))
        

        #3 Count remaining 1's not visited
        count = 0
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 1 and (row, col) not in visited:
                    count += 1

        return count



        