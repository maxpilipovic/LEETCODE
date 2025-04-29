class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        
        my_dict = {}

        def recursion(i, count):

            if i in my_dict:
                return my_dict[i]

            #Base Case
            if i >= len(cost):
                return 0
            
            #Recursive
            ans = cost[i] + min(recursion(i + 1, count), recursion(i + 2, count))
            my_dict[i] = ans

            return ans
        x1 = recursion(0, 0)
        x2 = recursion(1, 0)
        
        return min(x1, x2)