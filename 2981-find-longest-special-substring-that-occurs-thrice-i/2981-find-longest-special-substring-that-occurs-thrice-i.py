class Solution:
    def maximumLength(self, s: str) -> int:
        from collections import defaultdict
        my_dict = defaultdict(int)
        #hashy = set()
        #res = -1
        maxLen = -1

        i = 0

        while i < len(s):
            j = i

            while j < len(s) and s[i] == s[j]:
                j += 1
            
            length = j - i

            for l in range(1, length + 1):
                for k in range(i, j - l + 1):
                    substr = s[k:k + l]
                    my_dict[substr] += 1

            i = j

        print(my_dict)
        #print(hashy)
        #Sort
        #sorted_list = list(hashy)
        #sorted_list.sort()
        #print(sorted_list)

        for key, value in my_dict.items():

            if value >= 3:
                maxLen = max(maxLen, len(key))

        
        return maxLen #res if res >= 3 else -1


