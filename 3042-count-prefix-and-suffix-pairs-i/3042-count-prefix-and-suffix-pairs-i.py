class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:


        def isPrefixAndSuffix(prefix, word):

            if word.startswith(prefix) and word.endswith(prefix):
                return True

        hashy = set()
        count = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                print(words[i])
                print(words[j])
                if isPrefixAndSuffix(words[i], words[j]) == True:
                    count += 1
        
        return count
        

            
        