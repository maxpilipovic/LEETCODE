class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        
        res = 0

        for i in points:
            my_dict = {}
            for j in points:

                if i == j:
                    continue
                    
                dist = (i[0] - j[0])**2 + (i[1] - j[1]) ** 2
                
                if dist in my_dict:
                    my_dict[dist] += 1
                else:
                    my_dict[dist] = 1
            

            for value in my_dict.values():
                if value > 1:
                    res += value * (value - 1)
        
        return res

