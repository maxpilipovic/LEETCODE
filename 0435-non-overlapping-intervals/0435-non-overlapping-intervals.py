class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        
        sortedVals = sorted(intervals, key=lambda x: x[1])
        print(sortedVals)

        count = 0
        end = sortedVals[0][1] #Sets end to be 'end value' of the pair

        for i in range(1, len(sortedVals)):
            currStart, currEnd = sortedVals[i]

            if currStart < end:
                count += 1
            else:
                end = currEnd
            
        
        return count