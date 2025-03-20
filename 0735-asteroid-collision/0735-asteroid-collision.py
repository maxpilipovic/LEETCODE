class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        

        stack = []

        for value in asteroids:

            while stack and stack[-1] > 0 and value < 0:

                if abs(stack[-1]) > abs(value):
                    break
                elif abs(stack[-1]) == abs(value):
                    stack.pop()
                    break
                else:
                    stack.pop()
            else:
                stack.append(value)

        return stack              




        