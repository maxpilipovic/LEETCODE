class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        
        hashy = set(nums)
        res = []

        for i in range(1, len(nums) + 1):
            if i not in hashy:
                if i == 0:
                    continue
                res.append(i)
        
        return res



