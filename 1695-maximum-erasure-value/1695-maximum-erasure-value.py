class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        
        hashy = set()
        left = 0
        currSum = 0
        maxSum = float('-inf')

        for right in range(len(nums)):

            while nums[right] in hashy:
                currSum -= nums[left]
                hashy.remove(nums[left])
                left += 1
            
            hashy.add(nums[right])
            currSum += nums[right]
            maxSum = max(maxSum, currSum)

        return maxSum

