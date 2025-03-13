class Solution:
    def maximumCount(self, nums: List[int]) -> int:

        pos = 0
        neg = 0

        for i in nums:

            if i > 0:
                pos += 1
            elif i < 0:
                neg += 1
            else: #== 0
                continue

        return max(pos, neg) 


        