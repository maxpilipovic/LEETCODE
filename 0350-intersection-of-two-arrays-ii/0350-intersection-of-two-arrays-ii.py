class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        
        my_dict = Counter(nums1)
        res = []

        for i in nums2:
            if i in my_dict:
                res.append(i)
                my_dict[i] -= 1

                if my_dict[i] == 0:
                    del my_dict[i]

        return res

        
        