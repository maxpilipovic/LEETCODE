class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:

        my_dict = dict()

        for i in range(len(jewels)):
            if jewels[i] not in my_dict:
                my_dict[jewels[i]] = 1

        count = 0
        for i in range(len(stones)):
            if stones[i] in my_dict:
                count += 1

        return count
        