from collections import deque
class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        
        rows = len(grid)
        cols = len(grid[0])

        print(rows)
        print(cols)

        directions = [(-1, 0), (1, 0), (0, 1), (0, -1)] #Up, Down, Right, Left
        visited = set()
        queue = deque()


        def dfs(r, c):
            if (
                r < 0 or r >= rows or
                c < 0 or c >= cols or
                (r, c) in visited or
                grid[r][c] == 0
            ):
                return

            visited.add((r, c))
            queue.append((r, c))
            for dr, dc in directions:
                dfs(r + dr, c + dc)
        
        #Step 1: Find the first island and mark all cells
        queue = deque()
        found = False

        for r in range(rows):
            if found:
                break
            
            for c in range(cols):
                if grid[r][c] == 1:
                    dfs(r, c)
                    found = True
                    break
        
        #Step 2. Expand first island using BFS until we reach second island
        steps = 0
        while queue:

            for _ in range(len(queue)):
                row, col = queue.popleft()

                for nr, nc in directions:
                    newRow = row + nr
                    newCol = col + nc

                #Check our bounds
                    if 0 <= newRow < rows and 0 <= newCol < cols and (newRow, newCol) not in visited:
                        if grid[newRow][newCol] == 1:
                            return steps
                    
                        queue.append((newRow, newCol))
                        visited.add((newRow, newCol))

            steps += 1

        return -1 #Found nothing

                

