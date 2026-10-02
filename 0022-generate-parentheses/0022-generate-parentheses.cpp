class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        
        dfs(n, "", 0, 0);

        return res;
    }

    void dfs(int n, std::string curr, int oChar, int cChar)
    {
        //Base Case
        if (curr.size() == n * 2)
        {
            res.push_back(curr);
            return;
        }

        //Choose open char or close char
        if (oChar < n)
        {
            curr.push_back('(');
            dfs(n, curr, oChar + 1, cChar);
            curr.pop_back();
        }
        if (oChar > cChar)
        {
            curr.push_back(')');
            dfs(n, curr, oChar, cChar + 1);
            curr.pop_back();
        }
    }

private:
    vector<string> res;
};