class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        
        count = 0

        for i in range(len(arr) - 2):
            for j in range(i + 1, len(arr)):
                for k in range(i + 2, len(arr)):
                    if 0 <= i < j < k < len(arr):
                        if abs(arr[i] - arr[j]) <= a and abs(arr[j] - arr[k]) <= b and abs(arr[i] - arr[k]) <= c:
                            count += 1
        
        return count