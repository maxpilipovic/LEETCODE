class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:

        #Sort        
        nums.sort()
        print(nums)

        res = []
        left = 0

        for right in range(1, len(nums)):

            if nums[right] - nums[left] > k:
                res.append(nums[left:right])
                left = right
        
        res.append(nums[left:])
        print(res)

        return len(res)
        
        print(res)