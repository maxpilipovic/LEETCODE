class Solution:
    def smallestNumber(self, pattern: str) -> str:
        
        curr = []
        res = []
        used = set()

        def backtrack(curr):
            #Base Case
            if len(curr) == len(pattern) + 1:
                res.append("".join(map(str, curr)))
                return 

            #Recursive Case
            for num in range(1, 10): #Looks at numbers 1 - 9
                if num in used:
                    continue
                if curr and pattern[len(curr) - 1] == "I" and num < curr[-1]:
                    continue
                if curr and pattern[len(curr) - 1] == "D" and num > curr[-1]:
                    continue

                used.add(num)
                curr.append(num)
                backtrack(curr)
                curr.pop()
                used.remove(num)

        backtrack([])

        return res[0]