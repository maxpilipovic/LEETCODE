from collections import deque
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:

        rows = len(grid)
        cols = len(grid[0])

        queue = deque() #Keep track of our rotten oranges (r, c, 0)
        freshOranges = 0 #Keep track fresh oranges

        #1 Initialized our queue and kept track of fresh oranges 
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    queue.append((r, c, 0))
                elif grid[r][c] == 1:
                    freshOranges += 1
        
        #2 Loop through using bfs and make all oranges rotten
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        time = 0

        while queue:

            row, col, minutes = queue.popleft()

            #Update our time
            time = max(time, minutes)

            for dr, dc in directions:
                nr = dr + row
                nc = dc + col

                if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 1:
                    grid[nr][nc] = 2
                    freshOranges -= 1
                    queue.append((nr, nc, minutes + 1))

        
        return time if freshOranges == 0 else -1
        

                



        