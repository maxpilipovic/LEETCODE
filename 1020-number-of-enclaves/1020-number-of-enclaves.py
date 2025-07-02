from collections import deque
class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        

        rows = len(grid)
        cols = len(grid[0])
        directions = [(0, -1), (0, 1), (1, 0), (-1, 0)] #North, South, East, West
        count = 0

        def bfs(r, c, visited, directions):

            queue = deque()
            queue.append((r, c))
            visited.add((r, c))

            while queue:

                row, col = queue.popleft()

                #Check for boundary cell

                if row == 0 or row == rows - 1 or col == 0 or col == cols - 1:
                    return False
                
                for nr, nc in directions:

                    newRow = nr + row
                    newCol = nc + col

                    #Bounds
                    if 0 <= newRow < rows and 0 <= newCol < cols and grid[newRow][newCol] == 1 and (newRow, newCol) not in visited:
                        queue.append((newRow, newCol))
                        visited.add((newRow, newCol))
            
            return True

        for row in range(rows):
            for col in range(cols):

                if (row != 0 or row != rows - 1 or col != 0 or col != cols - 1) and grid[row][col] == 1:
                    if bfs(row, col, set(), directions):
                        count += 1
        
        return count