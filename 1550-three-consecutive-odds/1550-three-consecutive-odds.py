class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        
        threeConsectutive = 0
        flag = False

        for i in range(len(arr)):

            if arr[i] % 2 != 0:
                threeConsectutive += 1
                flag = True

                if threeConsectutive == 3:
                    return True
            elif arr[i] % 2 == 0 and flag == True:
                threeConsectutive = 0
        
        return False



        