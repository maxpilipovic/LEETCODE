class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        
        res = set()


        for i in range(len(nums)):

            if nums[i] == key:

                for j in range(len(nums)):
                    if abs(i - j) <= k:
                        res.add(j)
        
        return list(res)