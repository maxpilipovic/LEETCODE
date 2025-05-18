class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        
        #Sort. Lambda
        sortedIntervals = sorted(intervals, key=lambda x: x[0])
        res = [sortedIntervals[0]]

        for i in range(1, len(sortedIntervals)):
            prev = res[-1]
            curr = sortedIntervals[i]

            if curr[0] <= prev[1]:
                prev[1] = max(prev[1], curr[1])
            else:
                res.append(curr)
        
        return res

