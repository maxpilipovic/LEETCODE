class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:

        hashy = set(arr)
        maxLength = 0

        for i in range(len(arr)):
            for j in range(i + 1, len(arr)):
                
                length = 2
                first = arr[i]
                second = arr[j]

                while first + second in hashy:
                    third = first + second

                    first = second
                    second = third

                    length += 1
            
                maxLength = max(maxLength, length)

        return maxLength if maxLength >= 3 else 0


        
        
        