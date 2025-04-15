import heapq
from collections import defaultdict
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        
        res = []
        realPoints = []
        my_dict = defaultdict(list)

        for point in points:
            a, b = point
            ans = a*a + b*b
            my_dict[ans].append(point) 
            realPoints.append(ans)
        
        min_heap = realPoints.copy()
        heapq.heapify(min_heap)
        
        while k > 0:
            num = heapq.heappop(min_heap)
            point_list = my_dict[num]

            for pt in point_list:
                if k == 0:
                    break
                res.append(pt)
                k -= 1
        
        return res
            

        
        