from collections import deque
class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        
        rows = len(maze)
        cols = len(maze[0])

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)] #Up, Down, Left, Right
        visited = set()
        minCount = float('inf')
        queue = deque()

        tempRow = entrance[0]
        tempCol = entrance[1]

        #Check if its a border cell and append it to visited
        if tempRow == 0 or tempRow == rows - 1 or tempCol == 0 or tempCol == cols - 1:
            visited.add((tempRow, tempCol))

        queue.append((tempRow, tempCol, 0))

        while queue:

            row, col, count = queue.popleft()

            for nr, nc in directions:

                newRow = row + nr
                newCol = col + nc

                if 0 <= newRow < rows and 0 <= newCol < cols and maze[newRow][newCol] == "." and (newRow, newCol) not in visited:
                    
                    #Is it a border cell
                    if newRow == 0 or newRow == rows - 1 or newCol == 0 or newCol == cols - 1:
                        minCount = min(minCount, count + 1)
                    
                    visited.add((newRow, newCol))
                    queue.append((newRow, newCol, count + 1))

        return minCount if minCount != float('inf') else -1