class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        res = []
        my_dict = {}

        for i in strs:
            sortedi = list(i)
            sortedi.sort()
            print(sortedi)

            if str(sortedi) not in my_dict:
                my_dict[str(sortedi)] = []
                my_dict[str(sortedi)].append(i)
            else:
                my_dict[str(sortedi)].append(i)

        for value in my_dict.values():
            res.append(value)     

        return res       