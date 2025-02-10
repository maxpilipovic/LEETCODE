class Solution:
    def frequencySort(self, s: str) -> str:

        my_dict = dict()

        for char in s:
            if char in my_dict:
                my_dict[char] += 1
            else:
                my_dict[char] = 1
        

        #Sort chars based on freq
        sorted_items = sorted(my_dict.items(), key=lambda x: x[1], reverse=True)

        res = ""
        for key, value in sorted_items:
            res += key * value
        
        return res

        