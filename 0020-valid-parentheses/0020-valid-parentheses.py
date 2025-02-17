class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        openCount = 0
        openCount2 = 0
        openCount3 = 0

        for i in s:
            if i == "(":
                stack.append(i)
                openCount += 1
            elif i == "{":
                stack.append(i)
                openCount2 += 1
            elif i == "[":
                stack.append(i)
                openCount3 += 1
            elif i == ")":
                if openCount > 0 and stack and stack[-1] == "(":
                    stack.pop()
                    openCount -= 1
                else:
                    return False
            elif i == "}":
                if openCount2 > 0 and stack and stack[-1] == "{":
                    stack.pop()
                    openCount2 -= 1
                else:
                    return False
            elif i == "]":
                if openCount3 > 0 and stack and stack[-1] == "[":
                    stack.pop()
                    openCount3 -= 1
                else:
                    return False
        
        return openCount == 0 and openCount2 == 0 and openCount3 == 0


        



        