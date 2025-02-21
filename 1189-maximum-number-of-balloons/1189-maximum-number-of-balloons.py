class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:

        my_dict = {'b' : 0, 'a' : 0, 'l' : 0, 'o' : 0, 'n' : 0}

        for i in range(len(text)):
            if text[i] in my_dict:
                my_dict[text[i]] += 1

        minVal = float('inf')
        for key, value in my_dict.items():
            if key == 'l' or key == 'o':
                minVal = min(minVal, value // 2)
            else:
                minVal = min(minVal, value)

        return minVal