class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        
        hashy = set()

        for i in range(100):
            num1 = x ** i

            for j in range(100):
                num2 = y ** j

                total = num1 + num2
                if total <= bound:
                    hashy.add(total)

        return list(hashy)