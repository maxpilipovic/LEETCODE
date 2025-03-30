class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        
        my_dict = {}
        res = []

        #Make hashy storing last element of each index
        for i in range(len(s)):
            my_dict[s[i]] = i

        print(my_dict)

        #Two pointers
        start = 0
        max_end = 0

        for end in range(len(s)):

            max_end = max(my_dict[s[end]], max_end)
            
            if end == max_end:
                res.append(end - start + 1)
                start = end + 1
        

        return res

        