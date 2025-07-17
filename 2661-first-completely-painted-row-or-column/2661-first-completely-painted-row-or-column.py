class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        
        rows = len(mat) #2
        cols = len(mat[0]) #2

        print(rows)
        print(cols)
        my_dict = {}

        for i in range(rows):
            for j in range(cols):
                my_dict[mat[i][j]] = (i, j)

        print(my_dict)
        rowCount = [0] * rows 
        colCount = [0] * cols

        for num in range(len(arr)):

            if arr[num] in my_dict:
                row, col = my_dict[arr[num]]

                rowCount[row] += 1
                colCount[col] += 1

            #IS ==?
            if rowCount[row] == cols or colCount[col] == rows:
                print(rowCount)
                print(colCount)
                return num    
