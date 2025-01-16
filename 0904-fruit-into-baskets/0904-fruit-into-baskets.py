class Solution:
    def totalFruit(self, fruits: List[int]) -> int:

        fruitCount = dict()
        windowSize = 2
        maxNum = 0

        #first loop to create our window (2 elements)
        for num in range(len(fruits)):
            if len(fruitCount) == windowSize and fruits[num] not in fruitCount:
                break
            elif fruits[num] in fruitCount:
                fruitCount[fruits[num]] += 1
            else:
                fruitCount[fruits[num]] = 1
        
        #Create our left pointer
        left = 0

        maxNum = max(maxNum, sum(fruitCount.values()))

        #second loop as sliding window
        for right in range(num, len(fruits)):

            #Add new right
            fruitCount[fruits[right]] = 1 + fruitCount.get(fruits[right], 0)
            
            #Remove left
            while len(fruitCount) > windowSize:
                fruitCount[fruits[left]] -= 1

                #If theres only one
                if fruitCount.get(fruits[left]) == 0:
                    del fruitCount[fruits[left]]

                #Increment left
                left += 1

            #Update our max
            maxNum = max(maxNum, right - left + 1)
        
        return maxNum


            



        