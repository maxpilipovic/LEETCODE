class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:

        #Difference Array
        #Brute-Force (n^2)

        diffArray = [0] * (len(nums) + 1)

        for l, r in queries:
            diffArray[l] += 1
            diffArray[r + 1] -= 1
        
        print(diffArray)

        for i in range(1, len(nums)):
            diffArray[i] += diffArray[i - 1]
            print(diffArray[i])

        print(diffArray)

        for i in range(len(nums)):
            if nums[i] > diffArray[i]:
                return False
        
        return True