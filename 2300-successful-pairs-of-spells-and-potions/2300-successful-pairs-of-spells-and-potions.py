class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        
        #Sort
        potions.sort()
        res = []

        def binarySearch(value):

            left = 0
            right = len(potions) - 1

            while left <= right:
                mid = (right + left) // 2

                if (potions[mid] * value) >= success:
                    #Found it, but try to find smaller index
                    right = mid - 1
                else:
                    left = mid + 1
            
            return len(potions) - left
                  
        
        for i in spells:
            s = binarySearch(i)
            res.append(s)
        
        return res
