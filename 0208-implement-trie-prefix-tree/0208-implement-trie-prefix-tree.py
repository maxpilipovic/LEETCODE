class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfWord = False


class Trie:

    def __init__(self):
        self.root = TrieNode()
        

    def insert(self, word: str) -> None:

        curr = self.root

        for char in word:
            if char not in curr.children:
                #Add
                curr.children[char] = TrieNode()
            curr = curr.children[char]
        
        #Add endOfWord flag
        curr.endOfWord = True

    def search(self, word: str) -> bool:

        curr = self.root

        for char in word:
            if char not in curr.children:
                return False
            curr = curr.children[char]
        
        return curr.endOfWord 

    def startsWith(self, prefix: str) -> bool:
        curr = self.root

        for char in prefix:
            if char not in curr.children:
                return False
            curr = curr.children[char]
        
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)