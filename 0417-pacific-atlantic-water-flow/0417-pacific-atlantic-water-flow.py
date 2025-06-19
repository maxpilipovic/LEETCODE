from collections import deque
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        
        res = []
        rows = len(heights)
        cols = len(heights[0])
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)] #Up, Down, Left, Right

        def bfs(r, c, visited, directions):
            
            queue = deque()
            queue.append((r, c))
            visited.add((r, c))
            pacificOcean = False
            atlanticOcean = False

            while queue:


                row, col  = queue.popleft()

                #Check our flags.

                #Pacific
                if row == 0 or col == 0:
                    pacificOcean = True
                
                #Atlantic
                if row == rows - 1 or col == cols - 1:
                    atlanticOcean = True
                
                #Check if they hit.
                if pacificOcean and atlanticOcean:
                    return True

                for nr, nc in directions:

                    newRow = nr + row
                    newCol = nc + col

                    #Check bounds
                    if 0 <= newRow < rows and 0 <= newCol < cols and (newRow, newCol) not in visited and heights[row][col] >= heights[newRow][newCol]:

                        queue.append((newRow, newCol))
                        visited.add((newRow, newCol))
            
            return False

        for r in range(rows):
            for c in range(cols):
                if bfs(r, c, set(), directions):
                    res.append((r, c))

        
        return res
            
        



        