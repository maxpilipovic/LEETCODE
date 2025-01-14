class Solution(object):
    def climbStairs(self, n):

        my_dict = dict()

        def recursion(n):
            if n == 0:
                return 0

            if n == 1:
                return 1
        
            if n == 2:
                return 2

            if n in my_dict:
                return my_dict[n]
                
            my_dict[n] = recursion(n-1) + recursion(n-2)
            
            return my_dict[n]

        return recursion(n)
        