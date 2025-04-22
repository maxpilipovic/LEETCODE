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

        def bfs(row, col, visited, maxCount):
            queue = deque()
            queue.append((row, col, visited))
            visited.add((row, col))
            count = 1

            while queue:
                
                #Pop
                row, col, visited = queue.popleft()

                for nr, nc in directions:
                    newRow = row + nr
                    newCol = col + nc

                    if 0 <= newRow < rows and 0 <= newCol < cols and grid[newRow][newCol] == 1 and (newRow, newCol) not in visited:
                        visited.add((newRow, newCol))
                        queue.append((newRow, newCol, visited))
                        count += 1
            
            return count

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 1 and (row, col) not in visited:
                    count = bfs(row, col, visited, maxCount)
                    maxCount = max(maxCount, count)
        
        return maxCount


        
                