class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:

        stack = []
        resArray = [0] * len(temperatures)

        count = 0
        for i in range(len(temperatures)):

            while stack and temperatures[i] > temperatures[stack[-1]]:
                index = stack.pop()
                resArray[index] = i - index
            stack.append(i)

        return resArray


        