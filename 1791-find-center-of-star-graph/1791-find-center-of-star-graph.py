class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:

        my_dict = {}

        for a, b in edges:
            my_dict[a] = my_dict.get(a, 0) + 1
            my_dict[b] = my_dict.get(b, 0) + 1

            if my_dict[a] > 1:
                return a
            if my_dict[b] > 1:
                return b

        