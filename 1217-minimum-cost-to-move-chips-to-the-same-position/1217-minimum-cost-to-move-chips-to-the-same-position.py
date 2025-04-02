class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:

        #1 Calculate odds and evens
        evenCount = sum(1 for i in position if i % 2 == 0)
        oddCount = sum(1 for i in position if i % 2 != 0)

        return min(evenCount, oddCount)