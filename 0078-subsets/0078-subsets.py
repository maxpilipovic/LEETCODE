class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:

        res = []
        curr = []

        def dfs(i):
            #out-of-bounds
            if i >= len(nums):
                res.append(curr.copy())
                return curr


            #include one that adds
            curr.append(nums[i])
            dfs(i + 1)

            #includ oen that pops
            curr.pop()
            dfs(i + 1)
        
        dfs(0)

        return res
        
        