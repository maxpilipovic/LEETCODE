class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:

        my_dict = Counter(nums)

        #Find n
        n = len(nums) // 2
        
        for key, value in my_dict.items():
            if value == n:
                return key


        