from collections import deque
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        rows = len(grid)
        cols = len(grid[0])
        directions = [(0, -1), (0, 1), (1, 0), (-1, 0)] #Up, Down, Right, Left
        visited = set()
        maxCount = 0

        def bfs(r, c, visited, directions):

            queue = deque()
            queue.append((r, c))
            visited.add((r, c))
            area = 1

            while queue:
                row, col = queue.popleft()

                #Check count?

                for nr, nc in directions:

                    newRow = nr + row
                    newCol = nc + col

                    #Check bounds
                    if 0 <= newRow < rows and 0 <= newCol < cols and grid[newRow][newCol] == 1 and (newRow, newCol) not in visited:
                        queue.append((newRow, newCol))
                        visited.add((newRow, newCol))
                        area += 1
            
            return area



        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 1 and (row, col) not in visited:
                    x = bfs(row, col, visited, directions)
                    maxCount = max(maxCount, x)

        return maxCount
