from collections import deque
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        print(len(grid))
        print(len(grid[0]))
        rows = len(grid)
        cols = len(grid[0])

        queue = deque()
        freshOranges = 0

        #1. Put all rotten oranges in queue

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    print(r, c)
                    queue.append((r, c, 0)) #row, col, min
                elif grid[r][c] == 1:
                    freshOranges += 1
        
        #2: Loop through using bfs and make all oranges rotten
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)] #Right, Left, Down Up
        time = 0

        while queue:

            row, col, minute = queue.popleft()
            
            #Update our time
            time = max(time, minute)

            for dr, dc in directions:
                nr = dr + row
                nc = dc + col

                if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 1: #Fresh orange

                    grid[nr][nc] = 2 #Rotten Orange
                    freshOranges -= 1
                    queue.append((nr, nc, minute + 1))
                
            
        return time if freshOranges == 0 else -1


