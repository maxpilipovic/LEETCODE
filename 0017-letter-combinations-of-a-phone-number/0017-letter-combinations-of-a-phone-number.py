class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        
        if not digits:
            return []

        res = []
        graph = {
            2: ["a", "b", "c"],
            3: ["d", "e", "f"],
            4: ["g", "h", "i"],
            5: ["j", "k", "l"],
            6: ["m", "n", "o"],
            7: ["p", "q", "r", "s"],
            8: ["t", "u", "v"],
            9: ["w", "x", "y", "z"]
        }

        def backtrack(graph, index, curr):

            #Base Case
            if index == len(digits):
                res.append("".join(curr.copy()))
                return

            #Recursive
            for neighbor in graph[int(digits[index])]:
                curr.append(neighbor)
                backtrack(graph, index + 1, curr)
                curr.pop()
        

        backtrack(graph, 0, [])

        return res
