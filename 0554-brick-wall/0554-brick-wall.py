class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:

        my_dict = {}
        length = len(wall)

        for row in wall:
            prefixSum = 0

            for i in range(len(row) - 1):
                prefixSum += row[i]

                if prefixSum in my_dict:
                    my_dict[prefixSum] += 1
                else:
                    my_dict[prefixSum] = 1

        
        maxEdges = max(my_dict.values(), default = 0)

        return length - maxEdges
        
        


        