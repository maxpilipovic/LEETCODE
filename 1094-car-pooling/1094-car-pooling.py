class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        
        res = []
        x = 0

        for i in trips:
            passengers, start, end = i

            res.append((start, passengers))
            res.append(( end, -passengers))
        
        res.sort(key=lambda x: (x[0], x[1]))
        print(res)

        for i in res:
            x += i[1]
            
            if x > capacity:
                return False
        
        return True

        