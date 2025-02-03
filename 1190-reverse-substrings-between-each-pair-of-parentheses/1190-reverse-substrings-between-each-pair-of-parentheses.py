class Solution:
    def reverseParentheses(self, s: str) -> str:
        
        #Initalize stack
        stack = []

        for char in s:
            if char != ")":
                stack.append(char)
            elif char == ")":

                #Array to reverse
                reverseArray = []
                while stack[-1] != "(":
                    temp = stack.pop()
                    reverseArray.append(temp)

                #Pop the extra "("
                stack.pop()

                stack.extend(reverseArray)

        return "".join(stack)



            



        