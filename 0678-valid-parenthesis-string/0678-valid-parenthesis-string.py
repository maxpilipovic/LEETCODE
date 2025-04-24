class Solution:
    def checkValidString(self, s: str) -> bool:
        
        openStack = []
        starStack = []

        for i, char in enumerate(s):
            if char == "(":
                openStack.append(i)
            elif char == "*":
                starStack.append(i)
            else: #")"
                if openStack:
                    openStack.pop()
                elif starStack:
                    starStack.pop()
                else:
                    return False
        
        while openStack and starStack:
            if openStack[-1] < starStack[-1]:
                openStack.pop()
                starStack.pop()
            else:
                return False
        
        return not openStack

