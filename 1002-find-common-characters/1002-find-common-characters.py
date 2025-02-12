class Solution:
    def commonChars(self, words: List[str]) -> List[str]:

        cnt = Counter(words[0])

        #Builds hashmaps
        for w in words:
            cur_cnt = Counter(w)
            for key in cnt:
                cnt[key] = min(cnt[key], cur_cnt.get(key, 0))

        #Return
        res = []
        for key, count in cnt.items():
            res.extend([key] * count)
        
        return res

        

        


        