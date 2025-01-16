class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        #Add arrays together
        array = nums1 + nums2
        
        #Sort
        array.sort()

        #Total elements
        total = len(array)

        #If odd
        if total % 2 == 1:
            return float(array[total // 2])
        else:
            #If even, calculate average of two middle numbers
            middle1 = array[total // 2 - 1]
            middle2 = array[total // 2]
            return (float(middle1) + float(middle2)) / 2.0
        