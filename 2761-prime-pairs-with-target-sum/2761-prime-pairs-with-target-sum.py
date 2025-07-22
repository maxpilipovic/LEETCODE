class Solution:
    def findPrimePairs(self, n: int) -> List[List[int]]:
        
        def isPrime(n):

            primeNums = [True] * (n + 1)
            primeNums[0] = False
            primeNums[1] = False
            p = 2
            res = []

            while p * p <= n:

                if primeNums[p]:
                    for num in range(p * p, n + 1, p):

                        primeNums[num] = False
                
                p += 1
            
            for i in range(len(primeNums)):

                if primeNums[i]:
                    res.append(i)
            
            return res
        
        array = isPrime(n)
        finalRes = []

        #O(n^2)
        
        #Two Pointer
        
        left = 0
        right = len(array) - 1

        while left <= right:

            total = array[left] + array[right]

            if total == n:
                finalRes.append([array[left], array[right]])
                left += 1
                right -= 1
            elif total < n:
                left += 1
            else:
                right -= 1
        
        return finalRes








