class Solution:
    def decodeString(self, s: str) -> str:


        stack = []
        currString = ""
        currNum = 0

        for value in range(len(s)):
            
            if s[value].isdigit():
                #Build multi-digit numbers
                currNum = currNum * 10 + int(s[value])
            elif s[value] == "[":
                #Reset
                stack.append((currString, currNum))
                currString = ""
                currNum = 0
            elif s[value] == "]":
                prevString, num = stack.pop()
                currString = prevString + num * currString
                
            else: #String
                currString += s[value]
        
        return currString


        