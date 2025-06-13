from collections import deque
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        rows = len(grid)
        cols = len(grid[0])
        directions = [(0, -1), (0, 1), (1,0), (-1, 0)] #Up, Down, Right, Left
        visited = set()
        count = 0

        def bfs(r, c, visited, directions):
            
            queue = deque()
            queue.append((r, c))
            visited.add((r, c))

            while queue:

                row, col = queue.popleft()

                for nr, nc in directions:
                    newRow = nr + row
                    newCol = nc + col

                    if 0 <= newRow < rows and 0 <= newCol < cols and (newRow, newCol) not in visited and grid[newRow][newCol] == "1":
                        visited.add((newRow, newCol))
                        queue.append((newRow, newCol))


        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == "1" and (row, col) not in visited:
                    count += 1
                    bfs(row, col, visited, directions)
            
        return count