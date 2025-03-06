class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        
        missing = 0
        duplicate = 0
        flattenGrid = [i for s in grid for i in s]
        length = len(flattenGrid)
        my_dict = {}

        for i in range(length):
            print(flattenGrid[i])
            if flattenGrid[i] not in my_dict:
                my_dict[flattenGrid[i]] = 1
            else:

                duplicate = flattenGrid[i]
        
        for i in range(1, length + 1):
            if i not in my_dict:
                missing = i
                break

        return [duplicate, missing]

        