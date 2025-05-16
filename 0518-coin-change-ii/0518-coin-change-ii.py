class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        
        count = 0
        dp = {}

        def backtrack(i, profit):

            #nonlocal count

            #Base Case
            if profit == amount:
                return 1
            
            if profit > amount or i == len(coins):
                return 0
            

            if (i, profit) in dp:
                return dp[(i, profit)]
            
            #Recursive, we need to make some choices
            take = backtrack(i, profit + coins[i])
            skip = backtrack(i + 1, profit)

            dp[(i, profit)] = take + skip

            return dp[(i, profit)]

        return backtrack(0, 0)

