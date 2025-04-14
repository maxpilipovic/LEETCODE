class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        
        hashy = set()

        for i in nums:
            if i in hashy:
                return True
            else:
                hashy.add(i)
        
        return False