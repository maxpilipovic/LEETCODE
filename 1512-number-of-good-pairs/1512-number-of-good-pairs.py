class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        
        my_dict = dict()

        count = 0
        for i in range(len(nums)):
            if nums[i] in my_dict:
                count += my_dict[nums[i]]
                my_dict[nums[i]] += 1
            else:
                my_dict[nums[i]] = 1

        return count

            
        