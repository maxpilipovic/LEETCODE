from collections import deque
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:

        rows = len(grid)
        cols = len(grid[0])
        visited = set()
        directions =[(0, -1), (0, 1), (-1, 0), (1, 0)] #Up, Down, Left, Right
        islandCount = 0


        print(rows)
        print(cols)

        def bfs(row, col, visited, directions):
            queue = deque()
            queue.append((row, col, visited))

            while queue:
                row, col, visited = queue.pop()

                for nRow, nCol in directions:
                    newRow = row + nRow
                    newCol = col + nCol

                    if 0 <= newRow < rows and 0 <= newCol < cols and grid[newRow][newCol] == '1' and (newRow, newCol) not in visited:
                        visited.add((newRow, newCol))
                        queue.append((newRow, newCol, visited))

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == '1' and (row, col) not in visited:
                    print("Getting here")
                    islandCount += 1
                    visited.add((row, col))
                    bfs(row, col, visited, directions)

        return islandCount

        



        