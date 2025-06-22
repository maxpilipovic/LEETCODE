class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        
        count = 0
        res = []

        for i in range(0, len(s), k):

            curr = s[i:i + k]

            while len(curr) != k:

                curr += fill

            res.append(curr)
        
        return res


            
