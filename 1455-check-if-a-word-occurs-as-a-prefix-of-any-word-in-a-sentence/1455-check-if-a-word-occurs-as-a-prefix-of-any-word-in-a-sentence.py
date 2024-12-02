class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        array = []
        array = sentence.split()

        for word in range(len(array)):
            if array[word].startswith(searchWord):
                return word + 1
        return -1

        