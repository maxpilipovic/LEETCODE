class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        
        my_dict = {}

        for i in range(len(nums)): #Index value and ACTUAL value using range func

            if nums[i] in my_dict:
                
                for j in my_dict[nums[i]]: #Looping our values in the dict.
                    if abs(i - j) <= k:
                        return True
                my_dict[nums[i]].append(i)
            else:
                my_dict[nums[i]] = i #[] List
        

        return False


