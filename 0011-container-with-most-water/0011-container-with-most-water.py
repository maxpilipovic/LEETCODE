class Solution:
    def maxArea(self, height: List[int]) -> int:

        i = 0
        j = len(height) - 1

        maxRes = 0
        while i <= j:

            #Area of rectangle -> width * height

            #Get width
            width = j - i

            #Get height
            heightX = min(height[i], height[j])

            #Calculate
            maxRes = max(maxRes, width * heightX)
            
            #Bug - Not incrementing / dementing properly
            
            if height[j] > height[i]:
                i += 1
            else:
                j -= 1
        
        return maxRes






        