from collections import deque
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        

        rows = len(grid)
        cols = len(grid[0])
        queue = deque()
        visited = set()
        resMax = 0
        freshOranges = 0
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)] #North, South, East, West

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 2:
                    queue.append((row, col, 0))
                elif grid[row][col] == 1:
                    freshOranges += 1
        

        while queue:

            row, col, time = queue.popleft()

            resMax = max(resMax, time)

            for nr, nc in directions:

                newRow = nr + row
                newCol = nc + col

                if 0 <= newRow < rows and 0 <= newCol < cols and grid[newRow][newCol] == 1 and (newRow, newCol) not in visited:
                    visited.add((newRow, newCol))
                    queue.append((newRow, newCol, time + 1))
                    freshOranges -= 1
            
        
        return resMax if freshOranges == 0 else -1



