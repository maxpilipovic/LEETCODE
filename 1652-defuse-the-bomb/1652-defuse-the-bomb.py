class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:

        n = len(code)
        ans = [0] * n

        #case 1 - with zeros
        if k == 0:
            return ans
        
        #case 2 - k > 0
        if k > 0:
            for i in range(n):
                for j in range(1, k + 1):
                    print(i)
                    print(j)
                    ans[i] += code[(i+j) % n]


        
        #case 3 - k < 0 
        if k < 0:
            for i in range(n):
                for j in range(1, -k + 1):
                    ans[i] += code[(i-j) % n]

        return ans



        

        