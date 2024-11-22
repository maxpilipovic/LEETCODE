class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        def getRow(getRows):

            #Base case
            if getRows == 0:
                return [1]

            #Recurrsive case
            prevRow = getRow(getRows - 1)

            #Build row
            currRow = [1]
            for i in range(len(prevRow) - 1):
                currRow.append(prevRow[i] + prevRow[i+1])
            currRow.append(1)

            return currRow

        triangle = []

        for i in range(numRows):
            triangle.append(getRow(i))

        return triangle

        


        