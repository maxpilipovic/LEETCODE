class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        if not nums:
            return 0
        sortedNums = sorted(nums)

        curr = 1
        res = 1


        for i in range(len(sortedNums) - 1):
            if sortedNums[i] + 1 == sortedNums[i+1]:
                curr += 1
            elif sortedNums[i] != sortedNums[i+1]:
                res = max(res, curr)
                curr = 1

        return max(res, curr)




        