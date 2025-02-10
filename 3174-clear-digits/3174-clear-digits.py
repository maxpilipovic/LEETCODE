class Solution:
    def clearDigits(self, s: str) -> str:

        stack = []

        for value in s:
            if stack and not value.isalpha():
                stack.pop()
            else:
                stack.append(value)
        
        return "".join(stack)
        