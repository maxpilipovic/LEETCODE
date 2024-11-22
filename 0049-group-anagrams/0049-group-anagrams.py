class Solution(object):
    def groupAnagrams(self, strs):
        my_dict = dict()

        for i in strs:
            key = ''.join(sorted(i))

            if key in my_dict:
                my_dict[key].append(i)
            else:
                my_dict[key] = [i]
        
        return list(my_dict.values())


            

    

        

        
        