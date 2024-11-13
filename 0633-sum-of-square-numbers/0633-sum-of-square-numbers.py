class Solution(object):
    def judgeSquareSum(self, c):
        a = 0
        b = int(sqrt(c))
        while a <= b:
            ans = (a*a + b*b)
            print(ans)
            if ans == c:
                return True
            elif ans < c:
                a += 1
            else:
                b -= 1
        return False 

        