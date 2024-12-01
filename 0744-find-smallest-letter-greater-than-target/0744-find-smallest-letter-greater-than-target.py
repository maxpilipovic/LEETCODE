class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        my_dict = {
            'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5, 
            'f': 6, 'g': 7, 'h': 8, 'i': 9, 'j': 10,
            'k': 11, 'l': 12, 'm': 13, 'n': 14, 'o': 15, 
            'p': 16, 'q': 17, 'r': 18, 's': 19, 't': 20,
            'u': 21, 'v': 22, 'w': 23, 'x': 24, 'y': 25, 
            'z': 26
        }

        low = 0
        high = len(letters) - 1

        while low <= high:

            mid = low + ((high - low) // 2)
            midKey = letters[mid]

            if my_dict[midKey] <= my_dict[target]:
                low = mid + 1
            else:
                high = mid - 1
        return letters[low % len(letters)]



