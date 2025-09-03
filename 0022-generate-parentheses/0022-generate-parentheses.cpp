class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        dfs(res, curr, n, 0, 0);

        return res;
    }

    void dfs(vector<string>& res, std::string& curr, int n, int open_bracket, int closed_bracket)
    {
        
        //Base Case
        if (curr.size() == n * 2)
        {
            res.push_back(curr);
            return;
        }

        //Recursive ...
        //if?

        if (open_bracket < n) //Dont overthink... Gets us into the first backtrack iteration
        {
            curr.append("(");
            dfs(res, curr, n, open_bracket + 1, closed_bracket);
            curr.pop_back();
        }

        if (open_bracket > closed_bracket)
        {
            curr.append(")");
            dfs(res, curr, n, open_bracket, closed_bracket + 1);
            curr.pop_back();
        }
    }

private:
    vector<std::string> res;
    std::string curr;
};