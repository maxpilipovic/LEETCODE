class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:

        length = len(grid)
        my_dict = dict()
        res = 0

        #Rows
        for row in grid:
            rowTuple = tuple(row)
            if rowTuple in my_dict:
                my_dict[rowTuple] += 1
            else:
                my_dict[rowTuple] = 1
        
        #Cols
        for col in range(length):
            column = tuple(grid[r][col] for r in range(length))

            if column in my_dict:
                res += my_dict[column]
        
        return res
