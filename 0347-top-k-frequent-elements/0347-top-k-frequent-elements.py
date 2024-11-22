class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        my_dict = dict()

        for i in range(len(nums)):
            if nums[i] in my_dict:
                my_dict[nums[i]] += 1
            else:
                my_dict[nums[i]] = 1
            
        sorted_items = sorted(my_dict.items(), key=lambda x: x[1], reverse=True)

        top = [item[0] for item in sorted_items[:k]]

        return top