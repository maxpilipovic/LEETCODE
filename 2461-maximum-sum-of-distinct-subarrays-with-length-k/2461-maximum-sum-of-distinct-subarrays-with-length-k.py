class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:

        left = 0
        currentSum = 0
        maxNum = 0
        hashy = set()


        for right in range(len(nums)):
            if nums[right] not in hashy:
                currentSum += nums[right]
                hashy.add(nums[right])
            
                if right - left + 1 == k: #equal
                    if currentSum > maxNum:
                        maxNum = max(maxNum, currentSum)

                    currentSum -= nums[left]
                    hashy.remove(nums[left])
                    left += 1
            else:
                while nums[right] != nums[left]:
                    currentSum -= nums[left]
                    hashy.remove(nums[left])
                    left += 1

        return maxNum


            






        