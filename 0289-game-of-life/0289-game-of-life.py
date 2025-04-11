class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows = len(board)
        cols = len(board[0]) if rows > 0 else 0

        directions = [(-1, -1), (-1, 0), (-1, 1),
                      (0, -1),          (0, 1),
                      (1, -1),  (1, 0), (1, 1)]

        for row in range(rows):
            for col in range(cols):
                live_neighbors = 0
                for dr, dc in directions:
                    nr = row + dr
                    nc = col + dc
                    if 0 <= nr < rows and 0 <= nc < cols:
                        if board[nr][nc] == 1 or board[nr][nc] == -1:
                            live_neighbors += 1
                
                if board[row][col] == 1:
                    if live_neighbors < 2 or live_neighbors > 3:
                        board[row][col] = -1
                else:
                    if live_neighbors == 3:
                        board[row][col] = 2
        
        for row in range(rows):
            for col in range(cols):
                if board[row][col] == -1:
                    board[row][col] = 0
                elif board[row][col] == 2:
                    board[row][col] = 1
        