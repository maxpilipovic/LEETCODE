class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:

        count = 0
        length = max(arr) + 1
        res = set(arr)

        for i in range(1, length):

            if i in res:
                print(i)
            else:
                count += 1

                if count == k:
                    return i
        
        return max(arr) + (k - count)

        