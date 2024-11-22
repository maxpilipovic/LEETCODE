class Solution:
    def climbStairs(self, n: int) -> int:   

        my_dict = {}

        def recursion(n):
            if n == 0:
                return 0
            if n == 1:
                return 1

            if n == 2:
                return 2

            #if its computed
            if n in my_dict:
                return my_dict[n]

            #if its not computed
            my_dict[n] = recursion(n - 1) + recursion(n - 2)

            #return
            return my_dict[n]

        return recursion(n)
        