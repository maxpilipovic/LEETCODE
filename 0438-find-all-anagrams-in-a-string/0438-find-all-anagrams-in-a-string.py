class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:

        left = 0
        length = len(p)
        currWindow = []
        res = []

        for right in range(len(s)):
            currWindow.append(s[right])

            if len(currWindow) > length:
                currWindow.pop(0) #Removing leftist character
            
            if sorted(currWindow) == sorted(p):
                res.append(left) #Check if the same and append first character
            
            if len(currWindow) == length:
                left += 1 #Increase left pointer
        
        return res







        