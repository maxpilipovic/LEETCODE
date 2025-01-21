class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        
        res = []
        length = len(s)

        def backtrack(i, curr):
            
            #Base case
            if i == length:
                res.append("".join(curr))
                return

            #Recursive
            curr.append(s[i])
            backtrack(i + 1, curr)
            curr.pop()

            #Swap case
            if s[i].isalpha():
                curr.append(s[i].swapcase())
                backtrack(i + 1, curr)
                curr.pop()
        
        backtrack(0, [])
        return res



        