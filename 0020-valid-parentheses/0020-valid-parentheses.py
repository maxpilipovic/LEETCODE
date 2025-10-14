class Solution:
    def isValid(self, s: str) -> bool:

        flag = False
        stack = []

        #hashmap
        my_dict = {")" : "(", "}" : "{", "]" : "["}

        for char in s:

            if char in my_dict.values():
                stack.append(char)
            elif char in my_dict: #If we its a closing bracket..
                if not stack or stack.pop() != my_dict[char]:
                    flag = True
                    return False
        
        return len(stack) == 0
        

        #Everytime we see an opeing bracket. We want to append...
        #Ok is the stack empty? or the value at the topf of the stack is the my_dict[char] -> value...