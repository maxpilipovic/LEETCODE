class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:


        def isPrefixAndSuffix(prefix, word):

            n = len(prefix)

            if n > len(word):
                return False
            
            #Check prefix
            for i in range(n):
                if prefix[i] != word[i]:
                    return False
            
            #Check suffix
            for i in range(n):
                if prefix[i] != word[len(word) - n + i]:
                    return False
            
            return True

        count = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                print(words[i])
                print(words[j])
                if isPrefixAndSuffix(words[i], words[j]) == True:
                    count += 1
        
        return count
        

            
        