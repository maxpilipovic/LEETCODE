from collections import defaultdict
class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], numWanted: int, useLimit: int) -> int:
        
        #Sorting in decending order based on "value"
        items = sorted(zip(values, labels), key=lambda x: -x[0])
        print(items)

        my_dict = dict()
        res = 0

        for value, label in items:
            
            if numWanted == 0:
                break

            if my_dict.get(label, 0) < useLimit:
                res += value
                my_dict[label] = my_dict.get(label, 0) + 1
                numWanted -= 1
    

        return res
                




