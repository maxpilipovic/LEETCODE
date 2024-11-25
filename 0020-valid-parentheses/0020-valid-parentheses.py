class Solution:
    def isValid(self, s: str) -> bool:

        stack = []
        mapping = {
            ')': '(',
            '}': '{',
            ']': '['
        }


        for char in s:

            if char == '(' or char == '{' or char == '[':
                stack.append(char)

            elif char == ')' or char == '}' or char == ']':

                if not stack:
                    return False
                else:
                    top = stack.pop()
                    if (mapping[char] != top):
                        return False

        return not stack


        