class Solution:
    def minInsertions(self, s: str) -> int:
        
        openBracket = 0
        closingBracket = 0
        insertions = 0
        i = 0
        while i < len(s):
            if s[i] == "(":
                openBracket += 1
            else: #")"
                
                if i + 1 < len(s) and s[i+1] == ")":
                    i += 1
                else:
                    insertions += 1 #We neeed an extra ")"
                
                if openBracket >= 1:
                    openBracket -= 1
                else:
                    insertions += 1
        
            i += 1
        return insertions + openBracket * 2

        

            


        

        return openBracket + closedBracket




        