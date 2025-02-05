class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        
        stack = []
        res = []

        for char in range(len(s)):
            if s[char].isalpha():
                res.append(s[char])
            elif s[char] == "(":
                stack.append(char)
                res.append(s[char])
            elif s[char] == ")":
                if stack and s[stack[-1]] == "(":
                    stack.pop()
                    res.append(s[char])
                else:
                    stack.append(char)
                    res.append(s[char])

        while stack:
            temp = stack.pop()
            del res[temp]

        return "".join(res)

                    


