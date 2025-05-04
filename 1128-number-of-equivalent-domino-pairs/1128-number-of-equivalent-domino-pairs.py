class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        
        n = len(dominoes)
        my_dict = {}

        count = 0

        for a,b in dominoes:

            key = (a, b) if a <= b else (b, a)

            if key not in my_dict:
                my_dict[key] = 1
            else:
                count += my_dict[key]
                my_dict[key] += 1
        
        return count
            
