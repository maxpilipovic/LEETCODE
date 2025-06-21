class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        seenNumbers = {}

        for i, num in enumerate(nums):
            complement = target - num

            if complement in seenNumbers:
                return [seenNumbers[complement], i]

            seenNumbers[num] = i

        return []

            
