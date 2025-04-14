class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        
        hashy = set()
        res = set()

        for i in nums1:
            hashy.add(i)
        
        print(hashy)
        
        for i in nums2:
            if i in hashy:
                res.add(i)
        
        return list(res)