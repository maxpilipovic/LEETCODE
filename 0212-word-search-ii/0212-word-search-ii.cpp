class Solution {

private:

    struct Node 
    {
        bool isWord;
        unordered_map<char, Node*> map;
        Node() : isWord(false) {}
    };

    Node* root;
    vector<string> res;

public:

    Solution() 
    {
        root = new Node();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        
        //Add words
        for (string& word : words)
        {
            input(word);
        }

        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        //Loop over each char and perform dfs
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                //Run dfs from here...
                dfs(root, row, col, board, rows, cols, "", visited);
            }
        }

        return res;
    }

    void dfs(Node* curr, int row, int col, vector<vector<char>>& board, int rows, int cols, string path, vector<vector<bool>>& visited)
    {
        
        //Base Case
        if (row < 0 || col < 0 || col >= cols || row >= rows)
        {
            return;
        }   

        //Grab char and add to visited.
        char c = board[row][col];

        //Check if visited... Or not in TRIE
        if (visited[row][col] || curr->map.find(c) == curr->map.end())
        {
            return;
        }

        curr = curr->map[c];
        path.push_back(c);

        if (curr->isWord)
        {
            res.push_back(path);

            //Avoid duplicates
            curr->isWord = false;
        }

        //Add to visited.
        visited[row][col] = true;

        //DFS
        dfs(curr, row + 1, col, board, rows, cols, path, visited);
        dfs(curr, row, col + 1, board, rows, cols, path, visited);
        dfs(curr, row - 1, col, board, rows, cols, path, visited);
        dfs(curr, row, col - 1, board, rows, cols, path, visited);

        //Backtrack
        visited[row][col] = false;
    }


    void input(string& word)
    {

        Node* curr = root;

        for (char c : word)
        {
            
            if (curr->map.find(c) == curr->map.end())
            {
                curr->map[c] = new Node();
            }
            curr = curr->map[c];
        }
        curr->isWord = true;
    }


};