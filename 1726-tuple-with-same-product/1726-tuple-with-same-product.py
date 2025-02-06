class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        
        my_dict = dict()

        res = 0

        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                hereNum = (nums[i] * nums[j])
                if hereNum in my_dict:
                    my_dict[hereNum] += 1
                else:
                    my_dict[hereNum] = 1
        
        for key, value in my_dict.items():
            if value > 1:
                newNum = value - 1
                res += (value * (value - 1) // 2) * 8
        
        return res   




        