from collections import deque
class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        
        rows = len(grid)
        cols = len(grid[0])
        visited = set()
        directions = [(0, -1), (0, 1), (1, 0), (-1, 0)] #Up, Down, Right, Left
        count = 0

        def bfs(row, col, visited, directions):
            queue = deque()
            queue.append((row, col))
            visited.add((row, col))
            isClosed = True

            while queue:
                row, col = queue.popleft()
                
                #Check if its border
                if (row == 0 or row == rows - 1) or (col == 0 or col == cols - 1):
                    isClosed = False

                for nr, nc in directions:
                    newRow = nr + row
                    newCol = nc + col

                    #In-bounds
                    if 0 <= newRow < rows and 0 <= newCol < cols and grid[newRow][newCol] == 0 and (newRow, newCol) not in visited:
                        queue.append((newRow, newCol))
                        visited.add((newRow, newCol))

            return isClosed

        for row in range(rows):
            for col in range(cols):

                #Check
                if grid[row][col] == 0 and (row, col) not in visited:
                    if bfs(row, col, visited, directions):
                        count += 1
        
        return count
                


