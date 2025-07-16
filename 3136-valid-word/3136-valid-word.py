class Solution:
    def isValid(self, word: str) -> bool:
        
        vowelHashy = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}

        consonantHashy = {
    'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm',
    'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z',
    'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M',
    'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'
}

        numHashy = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}

        vowelFlag = False
        consonantFlag = False
        res = 0
        for char in word:

            if char in vowelHashy:
                if not vowelFlag:
                    vowelFlag = True
                res += 1
            elif char in consonantHashy:
                if not consonantFlag:
                    consonantFlag = True
                res += 1
            elif char in numHashy:
                res += 1
            else:
                return False
        
        print(vowelFlag)
        print(consonantFlag)
        return True if (res >= 3 and vowelFlag and consonantFlag) else False

        


