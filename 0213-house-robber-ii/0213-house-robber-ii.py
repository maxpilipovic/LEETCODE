class Solution:
    def rob(self, nums: List[int]) -> int:
        
        if len(nums) == 1:
            return nums[0]
            
        my_dict = {}
        my_dict2 = {}

        def robHouse(i, array, dictionary):

            #Base Case
            if i > len(array) - 1:
                return 0

            #Recursive WITH DP
            if i in dictionary:
                return dictionary[i]

            #Rob
            robIt = array[i] + robHouse(i + 2, array, dictionary)

            #Skip
            skipIt = robHouse(i + 1, array, dictionary)
            
            dictionary[i] = max(robIt, skipIt)

            return dictionary[i]


        firstArray = nums[1:]
        secondArray = nums[:len(nums) - 1]

        return max(robHouse(0, firstArray, my_dict), robHouse(0, secondArray, my_dict2))
        