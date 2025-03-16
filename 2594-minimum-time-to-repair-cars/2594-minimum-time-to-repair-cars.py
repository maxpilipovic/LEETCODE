class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:

        left = 1
        right = ranks[0] * cars * cars
        res = -1

        def countCars(time):
            count = 0

            for i in ranks:
                count += int(sqrt(time / i))
            
            return count

        while left <= right:

            #Calculate mid (time)
            mid = (left + right) // 2

            #For loop
            repaired = countCars(mid)

            if repaired >= cars:
                res = mid
                right = mid - 1
            else:
                left = mid + 1
            
        return res
           


        