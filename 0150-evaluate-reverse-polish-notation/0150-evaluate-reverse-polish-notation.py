class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        

        stack = []

        for i in tokens:
            if i.lstrip('-').isdigit():
                stack.append(int(i))
            else:
                first = stack.pop()
                second = stack.pop()

                if i == '+':
                    ans = second + first
                    stack.append(ans)
                elif i == '-':
                    ans = second - first
                    stack.append(ans)
                elif i == '*':
                    ans = second * first
                    stack.append(ans)
                elif i == '/':
                    ans = (int(second / first))
                    stack.append(ans)

        return stack[-1]




        