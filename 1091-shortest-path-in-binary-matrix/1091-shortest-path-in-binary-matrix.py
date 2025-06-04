from collections import deque
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        
        rows = len(grid)
        cols = len(grid[0])

        if grid[0][0] == 1 or grid[rows - 1][cols - 1] == 1:
            return -1

        print(rows)
        print(cols)

        directions = [(0, -1), (0, 1), (1, 0), (-1, 0), (1, 1), (-1, -1), (-1, 1), (1, -1)] #Up, Down, Right, Left
        queue = deque()
        queue.append((0,0,1))
        visited = set()
        visited.add((0,0))

        while queue:
            row, col, count = queue.popleft()

            if (row, col) == (rows - 1, cols - 1):
                return count

            for nr, nc in directions:
                newRow = nr + row
                newCol = nc + col

                if 0 <= newRow < rows and 0 <= newCol < cols and grid[newRow][newCol] == 0 and (newRow, newCol) not in visited:
                    visited.add((newRow, newCol))
                    queue.append((newRow, newCol, count + 1))
            

        return -1