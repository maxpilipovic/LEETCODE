class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        output = [""]

        for char in s:
            temp = []
            if char.isalpha():
                for o in output:
                    temp.append(o + char.lower())
                    temp.append(o + char.upper())
            else:
                for o in output:
                    temp.append(o + char)
            output = temp
        return output


        