class Solution:
    def longestPalindrome(self, s: str) -> int:
        #Create our res to return
        res = 0

        #Only for a singular '1'
        flag = False

        #Create the counter to hold values
        my_dict = Counter(s)
        print(my_dict)

        for key, value in my_dict.items():
            if value % 2 == 0:
                res += value
            else:
                res += value - 1

                #Found our odd
                flag = True
        
        #If res is odd
        if flag == True:
            return res + 1
        return res


        