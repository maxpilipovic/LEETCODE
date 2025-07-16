class Solution:
    def maximumGroups(self, grades: List[int]) -> int:
        
        grades.sort()
        groupSize = 1
        left = 0

        while left + groupSize <= len(grades):

            left += groupSize
            groupSize += 1
        
        return groupSize - 1

