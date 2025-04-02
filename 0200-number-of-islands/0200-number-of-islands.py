from collections import deque
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        islands = 0
        rows = len(grid)
        cols = len(grid[0])

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        visited = set()

        def dfs(r, c):
            stack = [(r, c)]
            visited.add((r, c))

            while stack:
                rowIsland, colIsland = stack.pop()

                for x, y in directions:
                    nRowIsland = x + rowIsland
                    nColIsland = y + colIsland

                    if 0 <= nRowIsland < rows and 0 <= nColIsland < cols and grid[nRowIsland][nColIsland] == '1' and (nRowIsland, nColIsland) not in visited:
                        stack.append((nRowIsland, nColIsland))
                        visited.add((nRowIsland, nColIsland))

        for r in range(rows):
            for c in range(cols):

                if grid[r][c] == '1' and (r, c) not in visited:
                    dfs(r, c)
                    islands += 1

        return islands


        