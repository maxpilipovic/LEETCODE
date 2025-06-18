class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:

        length = len(p)

        p_count = Counter(p)
        s_count = Counter(s[:len(p) - 1])
        res = []
        left = 0

        print(p_count)
        print(s_count)

        for right in range(len(p) - 1, len(s)):
            
            #Expand window
            s_count[s[right]] += 1

            #Check if the same
            if s_count == p_count:
                res.append(left)
            
            #Shrink window
            s_count[s[left]] -= 1

            if s_count[s[left]] == 0:
                del s_count[s[left]]
            
            left += 1

        return res






        