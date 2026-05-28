class Solution {

    struct TrieNode
    {
        int children[26];
        int index = -1;

        TrieNode()
        {
            fill(children, children + 26, -1);
            index = -1;
        }

    };

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) 
    {
        vector<TrieNode> trie;
        trie.push_back(TrieNode()); // root

        for (int i = 0; i < wordsContainer.size(); i++)
        {
            updateBest(trie[0], wordsContainer, i);
            insert(trie, wordsContainer, i);
        }

        vector<int> res;

        for (string& query : wordsQuery)
        {
            res.push_back(search(trie, query));
        }

        return res;
    }

    void insert(vector<TrieNode>& trie, vector<string>& wordsContainer, int idx)
    {
        string& word = wordsContainer[idx];
        int node = 0;

        for (int i = word.size() - 1; i >= 0; i--)
        {
            int c = word[i] - 'a';

            if (trie[node].children[c] == -1)
            {
                trie[node].children[c] = trie.size();
                trie.push_back(TrieNode());
            }

            node = trie[node].children[c];

            updateBest(trie[node], wordsContainer, idx);
        }
    }

    int search(vector<TrieNode>& trie, string& query)
    {
        int node = 0;

        for (int i = query.size() - 1; i >= 0; i--)
        {
            int c = query[i] - 'a';

            if (trie[node].children[c] == -1)
            {
                break;
            }

            node = trie[node].children[c];
        }

        return trie[node].index;
    }

    void updateBest(TrieNode& node, vector<string>& wordsContainer, int idx)
    {
        if (node.index == -1)
        {
            node.index = idx;
            return;
        }

        int current = node.index;

        if (wordsContainer[idx].size() < wordsContainer[current].size())
        {
            node.index = idx;
        }
    }

private:
    vector<int> res;
};