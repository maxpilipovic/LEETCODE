class Solution:
    def possibleStringCount(self, word: str) -> int:
        
        count = 1

        for num in range(1, len(word)):

            if word[num] == word[num - 1]:
                count += 1
        
        return count
