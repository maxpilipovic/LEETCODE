class Solution:
    def partition(self, s: str) -> List[List[str]]:

        res = []

        def isPalindrome(curr):
            
            left = 0
            right = len(curr) - 1

            while left < right:
                if curr[left] != curr[right]:
                    return False
                
                left += 1
                right -= 1

            return True

        def backtrack(index, curr):
            
            #Base Case
            if index == len(s):
                res.append(curr.copy())
                return
            
            #Recursive
            for end in range(index + 1, len(s) + 1):
                substr = s[index:end]
                if isPalindrome(substr):
                    curr.append(substr)
                    backtrack(end, curr)
                    curr.pop()

        backtrack(0, [])
        return res