class Solution:
    def maximumSum(self, nums: List[int]) -> int:

        my_dict = dict()

        for num in nums:
            sumDigit = sum([int(digit) for digit in str(num)])

            if sumDigit not in my_dict:
                my_dict[sumDigit] =[]
            
            my_dict[sumDigit].append(num)

        res = -1

        for numList in my_dict.values():
            if len(numList) > 1: #Only want to look for the number in list, e.g 2 values
                ans = sum(sorted(numList, reverse=True)[:2])
                res = max(res, ans)
        
        return res
                    
                    


        