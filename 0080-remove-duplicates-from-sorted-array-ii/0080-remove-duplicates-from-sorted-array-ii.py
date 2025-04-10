class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        
        if len(nums) < 2:
            return len(nums)

        write = 2

        for i in range(write, len(nums)):

            if nums[i] != nums[write - 2]:
                nums[write] = nums[i]
                write += 1
                print(write)
        return write

        