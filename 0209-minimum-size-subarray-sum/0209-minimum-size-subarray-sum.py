class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:

        minimumLength = float('inf')
        currentStreak = 0
        left = 0

        for right in range(len(nums)):
            #Add each right number
            currentStreak += nums[right]

            while currentStreak >= target:
                #Calculate index length
                length = (right - left) + 1

                #Update
                minimumLength = min(minimumLength, length)

                #Update left pointer and remove from currentStreak
                currentStreak -= nums[left]
                left += 1
        
        return minimumLength if minimumLength != float('inf') else 0


        