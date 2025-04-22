from collections import deque
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:

        rows = len(grid)
        cols = len(grid[0])
        visited = set()
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)] #Up, Down, Right, Left
        print(rows)
        print(cols)
        res = 0

        def bfs(row, col, visited):
            queue = deque()
            queue.append((row, col, visited))
            visited.add((row, col))

            while queue:
                
                #Pop
                row, col, visited = queue.popleft()

                for nr, nc in directions:
                    newRow = row + nr
                    newCol = col + nc

                    if 0 <= newRow < rows and 0 <= newCol < cols and grid[newRow][newCol] == 1 and (newRow, newCol) not in visited:
                        visited.add((newRow, newCol))
                        queue.append((newRow, newCol, visited))

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 1 and (row, col) not in visited:
                    res += 1
                    bfs(row, col, visited)
        
        return res


        
                