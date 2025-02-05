class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        res = []

        #First pass checking for extra ")"
        openCount = 0
        for char in s:
            if char.isalpha():
                res.append(char)
            elif char == "(":
                openCount += 1
                res.append(char)
            else:
                if openCount > 0:
                    res.append(")")
                    openCount -= 1
                else:
                    continue

        #Second pass and add extra "(" 
        closeCount = 0
        finalres = []

        for char in reversed(res):
            if char.isalpha():
                finalres.append(char)
            elif char == ")":
                closeCount += 1
                finalres.append(char)
            elif char == "(":
                if closeCount > 0:
                    finalres.append(char)
                    closeCount -= 1
                else:
                    continue

        #Return
        return "".join(reversed(finalres))


        
        