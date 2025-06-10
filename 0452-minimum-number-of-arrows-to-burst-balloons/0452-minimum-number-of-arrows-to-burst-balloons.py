class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        
        sortedPoints = sorted(points, key = lambda x: x[1])
        print(sortedPoints)
        count = 1

        firstTuple = sortedPoints[0]
        for i in range(1, len(points)):

            if firstTuple[1] >= sortedPoints[i][0]:
                continue
            else:
                count += 1
                firstTuple = sortedPoints[i]

        return count