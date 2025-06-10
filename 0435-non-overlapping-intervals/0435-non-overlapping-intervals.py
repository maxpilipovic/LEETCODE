class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        
        #Sort
        sortedIntervals = sorted(intervals, key=lambda x: x[1])
        print(sortedIntervals) 
        count = 0

        firstTuple = sortedIntervals[0]
        for i in range(1, len(sortedIntervals)):
            
            if firstTuple[1] > sortedIntervals[i][0]:
                count += 1
            else:
                firstTuple = sortedIntervals[i]
        
        return count