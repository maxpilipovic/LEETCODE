class Solution:
    def simplifyPath(self, path: str) -> str:
        parts = path.split("/")
        print(parts)
        stack = []

        for part in parts:

            if part == '' or part == '.':
                continue
            
            elif part == '..':
                if stack:
                    stack.pop()
            else:
                stack.append("/" + part)

        if stack:    
            return "".join(stack)
        else:
            return "/"
            
            


        