class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        
        max_i = nums[0]
        max_j = float('-inf')
        max_k = 0

        for j in range(1, len(nums) - 1):
                max_j = max(max_j, max_i - nums[j])
                max_k = max(max_k, max_j * nums[j + 1])
                max_i = max(max_i, nums[j])
        
        return max_k