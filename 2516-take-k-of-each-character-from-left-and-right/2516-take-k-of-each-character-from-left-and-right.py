class Solution:
    def takeCharacters(self, s: str, k: int) -> int:

        my_dict = {}

        for i in range(len(s)):
            if s[i] in my_dict:
                my_dict[s[i]] += 1
            else:
                my_dict[s[i]] = 1
        
        if my_dict.get('a', 0) < k or my_dict.get('b', 0) < k or my_dict.get('c', 0) < k:
            return -1

        res = float("inf")
        left = 0
        for right in range(len(s)):
            my_dict[s[right]] -= 1

            while min(my_dict.values()) < k:
                my_dict[s[left]] += 1
                left += 1

            res = min(res, len(s) - (right - left + 1))

        return res


        

        








        