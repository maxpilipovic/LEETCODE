from collections import deque
class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        
        length = len(board)

        board.reverse()
        def getBoardIndex(square):

            r = (square - 1) // length
            c = (square - 1) % length

            if r % 2 != 0: #Odd
                c = length - 1 - c

            return [r,c]

        
        queue = deque([(1, 0)]) # square, level
        visited = set()

        while queue:
            square, level = queue.popleft()

            for i in range(1, 7):
                nextSquare = square + i
                r, c = getBoardIndex(nextSquare)

                if board[r][c] != -1:
                    nextSquare = board[r][c]
                if nextSquare == length * length:
                    return level + 1
                if nextSquare not in visited:
                    visited.add(nextSquare)
                    queue.append([nextSquare, level + 1])

        return -1 