class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:

        my_dict = {}
        count = 0

        for i in range(len(nums1)):
            for j in range(len(nums2)):
                my_dict[nums1[i] + nums2[j]] = my_dict.get(nums1[i] + nums2[j], 0) + 1

        print(my_dict)
        for k in range(len(nums3)):
            for l in range(len(nums4)):
                target = -(nums3[l] + nums4[k])

                if target in my_dict:
                    count += my_dict[target]


        return count