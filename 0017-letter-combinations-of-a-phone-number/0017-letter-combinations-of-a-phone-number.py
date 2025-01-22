class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        
        #if digits dont exist
        if not digits:
            return []

        res = []
        curr = []

        my_dict = {2: 'abc', 3: 'def', 4: 'ghi', 5: 'jkl', 6: 'mno', 7: 'pqrs', 8: 'tuv', 9: 'wxyz'}

        def backtrack(index):

            #Base case
            if index == len(digits):
                res.append("".join(curr))
                return

            #Recursive
            for letter in my_dict[int(digits[index])]:
                curr.append(letter)
                backtrack(index + 1)
                curr.pop()

        backtrack(0)
        return res

            

        