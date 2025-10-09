class Trie {


private:

    struct Node 
    {
        bool isWord;
        unordered_map<char, Node*> children;

        //Constructor
        Node() : isWord(false) {}
    };

    Node* root; //Reference to our root.

public:
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        
        //1. Insert a word. 
        //2. Loop through every char
        Node* curr = root;

        for (char c : word)
        {
            if (curr->children.find(c) == curr->children.end())
            {
                //Not found!
                curr->children[c] = new Node();
            }
            //Move to next node..
            curr = curr->children[c];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        Node* curr = root;

        for (char c : word)
        {
            if (curr->children.find(c) == curr->children.end())
            {
                return false;
            }
            curr = curr->children[c];
        }

        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        
        Node* curr = root;

        for (char c : prefix)
        {
            if (curr->children.find(c) == curr->children.end())
            {
                return false;
            }
            curr = curr->children[c];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */