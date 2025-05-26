from collections import Counter
class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        
        count = Counter(words)
        maxLength = 0
        usedCenter = False
        print(count)
        
        for word, wordCount in count.items():
            print(word)
            print(wordCount)
            reversedWord = word[::-1]

            if word != reversedWord:
                if reversedWord in count:
                    pairs = min(count[word], count[reversedWord])
                    maxLength += pairs * 4
                    count[word] -= pairs
                    count[reversedWord] -= pairs
            else: #Word that is gg, ee, cc
                pairs = count[word] // 2
                maxLength += pairs * 4
                count[word] -= pairs * 2
        
        for word in count:
            if word[0] == word[1] and count[word] > 0:
                maxLength += 2
                break

        return maxLength
