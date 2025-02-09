class Solution:
    def removeStars(self, s: str) -> str:

        stack = []

        for val in s:
            #While stack is not empty 
            while stack and (stack[-1].isalpha() and val == "*"):
                stack.pop()
                break
            else:
                stack.append(val)
        
        return "".join(stack)

        