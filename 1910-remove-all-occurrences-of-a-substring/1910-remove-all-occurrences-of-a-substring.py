class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:

        stack = []
        window = len(part)

        for char in s:
            stack.append(char)

            if len(stack) >= window and "".join(stack[-window:]) == part:
                del stack[-window:]
            
            #char += 1
        
        return "".join(stack)

        
            
        