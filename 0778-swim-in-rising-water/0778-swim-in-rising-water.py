class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        #Dijikstra's + BFS

        rows = len(grid)
        cols = len(grid[0])

        minHeap = []
        minHeap.append((grid[0][0], 0, 0)) #w, x, y
        visited = set()
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)] #Up, Down, Left, Right
        
        while minHeap:
            w, x, y = heapq.heappop(minHeap)

            if (x, y) in visited:
                continue
            visited.add((x, y))

            if x == rows - 1 and y == cols - 1:
                if grid[x][y] > w:
                    return grid[x][y]
                else:
                    return w

            for nr, nc in directions:
                newRow = x + nr
                newCol = y + nc

                #Bounds
                if 0 <= newRow < rows and 0 <= newCol < cols and (newRow, newCol) not in visited:
                    if grid[newRow][newCol] > w:
                        heapq.heappush(minHeap, (grid[newRow][newCol], newRow, newCol))
                    else:
                        heapq.heappush(minHeap, (w, newRow, newCol))




        