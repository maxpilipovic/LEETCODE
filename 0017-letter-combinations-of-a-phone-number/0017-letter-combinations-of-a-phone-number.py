class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        
        if not digits:
            return []
            
        res = []
        my_dict = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        }

        def backtrack(i, curr):
            
            #Base Case
            if len(curr) == len(digits):
                res.append("".join(curr))
                return

            for num in my_dict[digits[i]]:
                curr.append(num)
                backtrack(i + 1, curr)
                curr.pop()
        
        backtrack(0, [])

        return res


