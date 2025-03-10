class Solution:
    def reverseVowels(self, s: str) -> str:
    
        my_dict = {'a': 1, 'e': 1, 'i': 1, 'o': 1, 'u': 1, 'A': 1, 'E': 1, 'I': 1, 'O': 1, 'U': 1}
        
        res = list(s)
        left = 0
        right = len(res) - 1

        while left < right:

            if res[left] in my_dict and res[right] in my_dict:
                #Swap
                res[left], res[right] = res[right], res[left]

                #Increment both
                left += 1
                right -= 1
        
            if res[left] not in my_dict:
                left += 1
        
            if res[right] not in my_dict:
                right -= 1

        return ''.join(res)



        