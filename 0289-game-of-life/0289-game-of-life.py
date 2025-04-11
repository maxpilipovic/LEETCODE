class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        rows = len(board)
        cols = len(board[0])

        directions = {(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (1, -1), (-1, 1), (1, 1)} #Left, Right, Up, Down, Up-Left, Up-Right, Down-Left, Down-Right

        for row in range(rows):
            for col in range(cols):
                count = 0

                for dr, dc in directions:
                    nr = dr + row
                    nc = dc + col

                    if 0 <= nr < rows and 0 <= nc < cols and (board[nr][nc] == 1 or board[nr][nc] == -1):
                         count += 1

                if board[row][col] == 1:
                    #Do something
                    if count < 2 or count > 3:
                        board[row][col] = -1 #Was alive but will die
                elif board[row][col] == 0:
                    #Do something
                    if count == 3:
                        board[row][col] = 2 #Was dead but will alive
        
        #Last step. Do final process and change grid
        for row in range(rows):
            for col in range(cols):
                if board[row][col] == -1:
                    board[row][col] = 0
                elif board[row][col] == 2:
                    board[row][col] = 1
        