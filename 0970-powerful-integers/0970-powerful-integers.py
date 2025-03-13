class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        
        hashy = set()

        for i in range(bound):
            num1 = x ** i
            for j in range(bound):
                num2 = y ** j

                ans = num1 + num2
                if ans <= bound:
                    hashy.add(ans)

        return list(hashy)