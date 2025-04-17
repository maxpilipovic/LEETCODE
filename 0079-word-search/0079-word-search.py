class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        
        rows = len(board)
        cols = len(board[0])
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)] #Up, Down, Left, Right

        print(rows)
        print(cols)

        def backtrack(row, col, index, visited):
            
            #Base Case
            if index == len(word) - 1:
                return True
            
            visited.add((row, col))

            #Recursive
            for dr, dc in directions:

                nr = row + dr
                nc = col + dc

                if 0 <= nr < rows and 0 <= nc < cols and (nr, nc) not in visited and board[nr][nc] == word[index + 1]:
                    if backtrack(nr, nc, index + 1, visited):
                        return True
            
            visited.remove((row, col))

            return False
        
        for row in range(rows):
            for col in range(cols):
                if board[row][col] == word[0]:
                    if backtrack(row, col, 0, set()):
                        return True
        
        return False







