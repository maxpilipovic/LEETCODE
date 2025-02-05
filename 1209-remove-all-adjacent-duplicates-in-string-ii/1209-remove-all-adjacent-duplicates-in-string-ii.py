class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:

        stack = []

        for char in s:
            #This case -> stack[-1][0] Indexes value (returns top of stack e.g 'a'). Compares with char
            #Comparing top of stack with char
            if stack and stack[-1][0] == char:
                #Accessing top of stack. Updating value...
                #Keep char the same.
                #Accessing second value in tuple [-1][1] and increasing by 1.
                stack[-1] = (char, stack[-1][1] + 1) #Increment count
                #If the [-1][1] (COUNT). So returns number, e.g 2 == k
                #If it is pop
                if stack[-1][1] == k:
                    stack.pop()
            else:
                #Else we append with a new value
                stack.append((char, 1))

        #Loops thru stack and -> char * count for (char, count) in stack
        return "".join(char * count for char, count in stack)

            


        