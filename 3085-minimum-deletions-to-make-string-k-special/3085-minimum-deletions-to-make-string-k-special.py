class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        
        freqList = list(Counter(word).values())
        print(freqList)
        deletes = float('inf')

        for i in range(len(freqList)):
            currDeletes = 0
            print(i)

            for j in range(len(freqList)):
                print(j)
                if freqList[j] < freqList[i]:
                    currDeletes += freqList[j]
                elif freqList[j] > freqList[i] + k:
                    currDeletes += freqList[j] - (freqList[i] + k)
        
            deletes = min(deletes, currDeletes)

        return deletes




