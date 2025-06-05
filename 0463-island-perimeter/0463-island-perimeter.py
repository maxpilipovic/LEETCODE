class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        
        def findEdges(row, col, directions):

            iCount = 0

            for nr, nc in directions:
                newRow = nr + row
                newCol = nc + col

                if 0 <= newRow < rows and 0 <= newCol < cols and grid[newRow][newCol] == 1:
                    iCount += 1
            
            if iCount == 2:
                return 2
            elif iCount == 1:
                return 3
            elif iCount == 4:
                return 0
            else:
                return 1
        
        
        totalCount = 0
        directions = [(0, -1), (0, 1), (1, 0), (-1, 0)] #Up, Down, Right, Left
        rows = len(grid)
        cols = len(grid[0])

        print(rows)
        print(cols)
        
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 1:
                    totalCount += 1
        
        #Edge Case
        if totalCount == 1:
            return 4

        count = 0
        #Loop
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 1:
                    #Helper function
                    edges = findEdges(row, col, directions)
                    print(edges)
                    count += edges

        return count

