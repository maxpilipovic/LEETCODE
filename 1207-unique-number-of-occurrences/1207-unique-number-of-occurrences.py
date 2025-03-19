class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:

        my_dict = Counter(arr)
        hashy = set()
        
        for value in my_dict.values():
            if value not in hashy:
                hashy.add(value)
            else:
                return False

        return True
        