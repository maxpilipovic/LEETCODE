class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        
        stack = []

        for char in s:
            if char == "(":
                stack.append(char)
            elif char == ")":
                if stack and stack[-1] == "(":
                    stack.pop()
                else:
                    stack.append(char)
            
        return len(stack)


        


        '''
        #Reps opens
        count1 = 0

        #Reps closes
        count2 = 0
        for char in s:
            if char == "(":
                count1 += 1
            elif char == ")":
                if count1 > 0:
                    count1 -= 1
                else:
                    count2 += 1
        
        return count1 + count2
        '''


        

        


        