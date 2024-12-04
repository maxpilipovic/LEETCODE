class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        
        my_dict = {
            'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6,
            'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13,
            'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20,
            'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25
        }

        j = 0
        for i in range(len(str1)):
            currentStr1 = my_dict[str1[i]]
            currentStr2 = my_dict[str2[j]]


            if currentStr1 == currentStr2 or (currentStr1 + 1) % 26 == currentStr2:
                j += 1

            if j == len(str2):
                return True
        return False
            

        