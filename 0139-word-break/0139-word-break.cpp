class Solution {
private:

    struct Node
    {
        bool isWord;
        unordered_map<char, Node*> children;

        Node() : isWord(false) {}
    };

    Node* root;

public:

    Solution() 
    {
        root = new Node();
    }

    bool wordBreak(string s, vector<string>& wordDict) 
    {
        //Put the word inside...

        for (auto& w : wordDict)
        {
            insertWord(w);
        }

        //dfs + memo?
        //allocate map or vector???
        unordered_map<int, bool> memo; 
        return dfs(s, 0, memo);
    }

    bool dfs(const string s, int index, unordered_map<int, bool> memo)
    {

        //Base Case???
        if (index >= s.size())
        {
            //We at the end so we know its true...
            return true;
        }

        //Memo base case...
        if (memo.count(index))
        {
            return memo[index];
        }

        Node* curr = root;

        for (int i = index; i < s.size(); i++)
        {
            if (curr->children.find(s[i]) == curr->children.end())
            {
                //If we dont find it..
                break;
            }

            //Move our pointer...
            curr = curr->children[s[i]];

            if (curr->isWord && dfs(s, i + 1, memo))
            {
                return memo[i] = true;
            }


        }

        return memo[index] = false;
    }

    void insertWord(string s)
    {
        Node* curr = root;

        for (char c : s)
        {
            //Check if it exists?
            if (curr->children.find(c) == curr->children.end())
            {
                curr->children[c] = new Node();
            }
            //Move to next node...
            curr = curr->children[c];
        }

        curr->isWord = true;
    }

};