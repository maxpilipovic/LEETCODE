class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:

        stack = []

        for val in asteroids:
            while stack and (stack[-1] > 0 and val < 0):
                if abs(stack[-1]) > abs(val):
                    break
                elif abs(stack[-1] == abs(val)):
                    stack.pop()
                    break
                else:
                    stack.pop()
            else:
                #if stack is empty
                stack.append(val)


        return stack
                



        