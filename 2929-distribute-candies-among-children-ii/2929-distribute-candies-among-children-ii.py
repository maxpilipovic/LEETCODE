class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        
        #Did not get by myself, learned combinatorics.
        
        minFirst = max(0, n - 2 * limit)
        maxFirst = min(n, limit)

        count = 0

        for i in range(minFirst, maxFirst + 1):
            N = n - i

            minC2 = max(0, N - limit)
            maxC2 = min(N, limit)

            count += maxC2 - minC2 + 1
        
        return count