class Solution:
    def largestAltitude(self, gain: List[int]) -> int:

        res = []
        prefixSum = 0
        maxAlt = 0
        for i in range(len(gain)):
            prefixSum += gain[i]
            print(prefixSum)
            maxAlt = max(maxAlt, prefixSum)
            res.append(prefixSum)

        print(res)
        return maxAlt
        