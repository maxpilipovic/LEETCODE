class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        


        #Edge case if integer is less then K
        for i in nums:
            if i < k:
                return -1

        count = 0
        hashy = set()

        for i in nums:
            print(i)
            if i > k:
                hashy.add(i)
        print(hashy)
        return len(hashy)