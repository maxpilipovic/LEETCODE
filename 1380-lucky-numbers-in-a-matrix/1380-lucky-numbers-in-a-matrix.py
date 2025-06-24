class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        
        #List Comprehension
        rowList = [min(row) for row in matrix]
        colList = [max(col) for col in zip(*matrix)]

        res = []

        for row in matrix:
            for num in row:
                if num in rowList and num in colList:
                    res.append(num)
        
        return res
        print(rowList)
        print(colList)




