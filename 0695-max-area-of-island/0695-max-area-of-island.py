from collections import deque
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        def bfs(row, col, visited, directions):
            queue = deque()
            queue.append((row, col))
            visited.add((row, col))
            area = 1

            while queue:
                currRow, currCol = queue.pop()

                for nRow, nCol in directions:
                    newRow = nRow + currRow
                    newCol = nCol + currCol

                    if 0 <= newRow < rows and 0 <= newCol < cols and grid[newRow][newCol] == 1 and (newRow, newCol) not in visited:
                        visited.add((newRow, newCol))
                        queue.append((newRow, newCol))
                        area += 1
            
            return area

        rows = len(grid)
        cols = len(grid[0])
        visited = set()
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)] #Left, Right, Up, Down
        returnRes = 0

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 1:
                    returnRes = max(returnRes, bfs(row, col, visited, directions))
        
        return returnRes
        

