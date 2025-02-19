class Solution:
    def smallestNumber(self, pattern: str) -> str:
        
        res = ""
        stack = []

        for i, char in enumerate(pattern + "I", 1): #Iterating over pattern + "I" with i and char, starting from 1
            stack.append(str(i))

            while stack and char == "I":
                res += stack.pop()

        return res

