from collections import deque
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        
        res = []
        rows = len(heights)
        cols = len(heights[0])
        directions = [(0, 1), (0, -1), (-1, 0), (1, 0)] #Up, Down, Left, Right


        def bfs(row, col):
            queue = deque()
            queue.append((row, col))
            visited = set()
            visited.add((row, col))

            pOcean = False
            aOcean = False

            while queue:
                row, col = queue.popleft()

                #Check if cell borders ocean
                if row == 0 or col == 0:
                    pOcean = True
                if row == rows - 1 or col == cols - 1:
                    aOcean = True
                
                if pOcean and aOcean:
                    return True

                #Loop through neighbors
                for nr, nc in directions:
                    newRow = nr + row
                    newCol = nc + col

                    if 0 <= newRow < rows and 0 <= newCol < cols and heights[newRow][newCol] <= heights[row][col] and (newRow, newCol) not in visited:

                        queue.append((newRow, newCol))
                        visited.add((newRow, newCol))
            
            return False

        for row in range(rows):
            for col in range(cols):
               if bfs(row, col):
                    res.append([row, col]) 
        
        return res


        