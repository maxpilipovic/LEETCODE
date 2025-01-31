class Solution:
    def simplifyPath(self, path: str) -> str:
        
        stack = []
        parts = path.split("/")

        for i in parts:
            #Go back a directory
            if i == "..":
                #If stack is empty
                if stack:
                    stack.pop()
            #Check if part is empty and i != "."
            elif i and i != ".":
                stack.append(i)
        
        return "/" + "/".join(stack)
        