class Solution:
    def triangleType(self, nums: List[int]) -> str:
        
        my_dict = Counter(nums)

        a, b, c = sorted(nums)
        print(a)

        if a + b <= c:
            return "none"

        if len(my_dict) == 1:
            return "equilateral"
        elif len(my_dict) == 2:
            return "isosceles"
        else:
            return "scalene"