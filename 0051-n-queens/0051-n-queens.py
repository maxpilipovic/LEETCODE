from collections import deque
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        
        #BACKTRACKING FUNCTION
        #Safe Function? Checking to to see if the Q we place is valid.

        res = []

        #List comprehension
        board = [["."] * n for _ in range(n)]
        print(board)

        #Helper function - Checks safe
        def isSafe(row, col):

            directions = [(-1 ,-1), (1,-1), (-1 ,1), (1, 1)] #DiagTopLeft, DiagTopRight, DiagBottomLeft, DiagBottomRight
            #Col
            for i in range(row):
                if board[i][col] == "Q":
                    return False
            
            #Diagonal
            #While loop to walk along diagonals

            #Top Left
            r = row - 1
            c = col - 1
            while r >= 0 and c >= 0:
                if board[r][c] == "Q":
                    return False

                r -= 1
                c -= 1

            #Top Right
            r = row - 1
            c = col + 1
            while r >= 0 and c <= n - 1:
                if board[r][c] == "Q":
                    return False
                
                r -= 1
                c += 1

            return True

        def backtrack(row):
            if row == n:
                res.append(["".join(r) for r in board])
                #Exit
                #Res.append
            for col in range(n):
                if isSafe(row, col):
                    board[row][col] = "Q"
                    backtrack(row + 1)
                    board[row][col] = "."

        backtrack(0)

        return res
