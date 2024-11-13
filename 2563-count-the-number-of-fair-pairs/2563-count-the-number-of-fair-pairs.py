class Solution(object):
    def countFairPairs(self, nums, lower, upper):

        def countFunc(x):
            count = 0
            i = 0
            j = len(nums) - 1

            while i < j:
                while i < j and nums[i] + nums[j] >= x:
                    j -= 1
                count += j - i
                i += 1
            return count

        nums.sort()
        return countFunc(upper + 1) - countFunc(lower)
        