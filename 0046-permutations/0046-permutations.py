class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        length = len(nums)
        curr = []
        res = []

        def backtrack():
            #Base case
            if len(curr) == length:
                res.append(curr.copy())
                return

            for i in range(length):
                
                #Removes duplicates from permutations
                if nums[i] in curr:
                    continue

                #Append curr
                curr.append(nums[i])

                #Backtrack
                backtrack()

                #Pop to go back
                curr.pop()
            
        backtrack()

        return res
            



        