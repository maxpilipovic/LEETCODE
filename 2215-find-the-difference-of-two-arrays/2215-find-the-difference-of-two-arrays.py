class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:

        answer = []
        curr1 = []
        curr2 = []
        uniquenums1 = set(nums1)
        uniquenums2 = set(nums2)

        for i in uniquenums1:
            if i in nums2:
                continue
            else:
                curr1.append(i)
        
        answer.append(curr1)

        for i in uniquenums2:
            if i in nums1:
                continue
            else:
                curr2.append(i)
        
        answer.append(curr2)
    
        return answer        
        