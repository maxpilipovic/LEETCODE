class Trie {

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        
        Node* curr = root;

        for (char c : word)
        {
            if (curr->map.find(c) == curr->map.end())
            {
                //New node (does not exist)
                curr->map[c] = new Node();
            }
            //Moves the pointer...
            curr = curr->map[c];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        Node* curr = root;

        for (char c : word)
        {
            if (curr->map.find(c) == curr->map.end())
            {
                //Not found...
                return false;
            }
            //Move the pointer
            curr = curr->map[c];
        }

        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;

        for (char c : prefix)
        {
            if (curr->map.find(c) == curr->map.end())
            {
                //Not found
                return false;
            }
            //Move the pointer
            curr = curr->map[c];
        }

        return true;
    }

private:
    struct Node
    {
        bool isWord;
        unordered_map<char, Node*> map;

        Node() : isWord(false) {}

    };

    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */