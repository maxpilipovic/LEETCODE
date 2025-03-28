class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:

        boxTypes.sort(key=lambda x: x[1], reverse=True) #Sort in decending
        print(boxTypes)

        totalUnits = 0

        for box in boxTypes:

            if truckSize == 0:
                break

            #Calculating the minimum amount of boxes we can take
            takeBoxes = min(box[0], truckSize)

            #Calculating the total units * how many boxes we have
            totalUnits += takeBoxes * box[1]

            #Here updating truck size (storage)
            truckSize -= takeBoxes

        return totalUnits
                    




        
        