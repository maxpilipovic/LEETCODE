class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:

        count = 0
        array = []

        my_dict = dict()

        for i in range(len(A)):
            #A
            if A[i] in my_dict:
                my_dict[A[i]] += 1
            else:
                my_dict[A[i]] = 1
            
            #B
            if B[i] in my_dict:
                my_dict[B[i]] += 1
            else:
                my_dict[B[i]] = 1
            
            #Check dict for size above 2
            for value in my_dict.values():
                if value >= 2:
                    count += 1
            
            array.append(count)
            count = 0

        return array
                


            
            
            
        