class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:

        s1_map = Counter(s1.split())
        s2_map = Counter(s2.split())
        res = []

        #Do it for s1
        for key, value in s1_map.items():
            if key not in s2_map and value < 2:
                res.append(key)
        
        #Do it for s2
        for key, value in s2_map.items():
            if key not in s1_map and value < 2:
                res.append(key)
        

        return res
        

