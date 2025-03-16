class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:

        if len(word1) != len(word2):
            return False

        word1Map = Counter(word1)
        word2Map = Counter(word2)

        if set(word1Map.keys()) != set(word2Map.keys()):
            return False
        
        if sorted(word1Map.values()) != sorted(word2Map.values()):
            return False
        
        return True
        