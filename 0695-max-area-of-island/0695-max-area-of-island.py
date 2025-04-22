from collections import deque
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:

        rows = len(grid)
        cols = len(grid[0])
        visited = set()
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)] #Up, Down, Right, Left
        print(rows)
        print(cols)
        maxCount = 0

        def dfs(row, col, visited, maxCount):
            stack = []
            stack.append((row, col, visited))
            visited.add((row, col))
            count = 1

            while stack:

                row, col, visited = stack.pop()

                for nr, nc in directions:
                    newRow = nr + row
                    newCol = nc + col

                    if 0 <= newRow < rows and 0 <= newCol < cols and grid[newRow][newCol] == 1 and (newRow, newCol) not in visited:
                        count += 1
                        visited.add((newRow, newCol))
                        stack.append((newRow, newCol, visited))
            
            return count

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 1 and (row, col) not in visited:
                    count = dfs(row, col, visited, maxCount)
                    maxCount = max(maxCount, count)
        
        return maxCount


        
                