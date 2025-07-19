class Solution:
    def minCost(self, arr: List[int], brr: List[int], k: int) -> int:
        
        def score(array1, array2):

            res = 0

            for a, b in zip(array1, array2):
                res += abs(a - b)

            return res

        return min(score(arr, brr), score(sorted(arr), sorted(brr)) + k)