from collections import deque
class Solution:
    def solve(self, board: List[List[str]]) -> None:

        rows = len(board)
        cols = len(board[0])

        print(rows)
        print(cols)

        visited = set()
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)] #Up, Down, Left, Right
        
        def bfs(row, col, visited, directions, path):

            queue = deque()
            queue.append((row, col))
            visited.add((row, col))
            path.append((row, col))
            edgeCell = False

            if row == 0 or row == rows - 1 or col == 0 or col == cols - 1:
                print("Getting here")
                edgeCell = True

            while queue:

                row, col = queue.popleft()

                for nr, nc in directions:
                    newRow = nr + row
                    newCol = nc + col

                    if 0 <= newRow < rows and 0 <= newCol < cols and (newRow, newCol) not in visited and board[newRow][newCol] == 'O':
                        
                        #Check if its an edge
                        if newRow == 0 or newRow == rows - 1 or newCol == 0 or newCol == cols - 1:
                            print("Getting here")
                            edgeCell = True
                        
                        #Add to current path, visited and queue
                        path.append((newRow, newCol))
                        queue.append((newRow, newCol))
                        visited.add((newRow, newCol))
            
            if edgeCell == False:

                for oldRow, oldCol in path:
                    board[oldRow][oldCol] = 'X'


        for row in range(rows):
            for col in range(cols):
                if board[row][col] == 'O' and (row, col) not in visited:
                    bfs(row, col, visited, directions, [])