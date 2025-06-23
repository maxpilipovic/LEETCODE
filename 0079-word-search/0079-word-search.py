class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        
        temp = word[0]
        print(temp)

        rows = len(board)
        cols = len(board[0])
        directions = [(0, -1), (0, 1), (1, 0), (-1, 0)] #Up, Down, Right, Left

        def dfs(r, c, visited, index):
            
            if (r < 0) or (r >= rows) or (c < 0) or (c >= cols) or board[r][c] != word[index] or (r, c) in visited:
                return False
            
            #Base Case
            if len(word) - 1 == index:
                #Out of bounds? Past -> word
                return True

            visited.add((r, c))
            #Recursive
            for nr, nc in directions:
                newRow = nr + r
                newCol = nc + c

                #Bounds?
                if dfs(newRow, newCol, visited, index + 1):
                    return True
                
            visited.remove((r, c))
            
            return False

        for row in range(rows):
            for col in range(cols):

                if board[row][col] == temp:
                    if dfs(row, col, set(), 0):
                        return True
        
        return False
        