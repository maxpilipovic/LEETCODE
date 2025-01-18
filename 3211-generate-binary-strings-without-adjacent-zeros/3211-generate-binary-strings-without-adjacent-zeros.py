class Solution:
    def validStrings(self, n: int) -> List[str]:

        res = []

        def recursive(i):

            if len(i) == n:
                res.append(i)
                return
            
            #two decisions

            #1 Add '1'
            recursive(i + "1")

            #2 Add '0' only if the last character is not '0'
            if not i or i[-1] != '0':
                recursive(i + "0")
        
        recursive("")
        return res



        