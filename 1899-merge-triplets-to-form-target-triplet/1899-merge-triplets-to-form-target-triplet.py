class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:

        x, y, z = target
        foundX = False
        foundY = False
        foundZ = False

        for a, b, c in triplets:
            
            #If greater, skip triplet
            if a > x or b > y or c > z:
                continue
            
            if a == x and b <= y and c <= z:
                foundX = True
            if b == y and a <= x and c <= z:
                foundY = True
            if c == z and a <= x and b <= y:
                foundZ = True

        return foundX and foundY and foundZ

        