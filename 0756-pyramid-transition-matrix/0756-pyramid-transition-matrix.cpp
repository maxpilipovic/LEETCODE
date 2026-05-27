class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) 
    {
        int n = bottom.size();
        
        //Build Map
        BuildMap(allowed);
        
        return backtrack(bottom);
    }

    bool backtrack(string curr)
    {
        if (curr.size() == 1)
        {
            return true;
        }

        if (memo.contains(curr))
        {
            return memo[curr];
        }

        std::string newString = "";

        bool result = buildNextRow(curr, 0, newString);
        memo[curr] = result;

        return result;
    }

    bool buildNextRow(std::string& curr, int i, std::string& newString)
    {
        
        //Bounds check
        if (i == curr.size() - 1)
        {
            return backtrack(newString);
        }

        string x;
        x += curr[i];    
        x += curr[i + 1];

        if (!res.contains(x))
        {
            return false;
        }

        for (char c: res[x])
        {
            newString += c;
            
            if (buildNextRow(curr, i + 1, newString))
            {
                return true;
            }

            newString.pop_back();
        }

        return false;
    }

    void PrintMap(const std::unordered_map<std::string, std::vector<char>>& res)
    {
        for (const auto& [key, values] : res)
        {
            std::cout << key << " -> ";

            for (char c : values)
            {
                std::cout << c << ' ';
            }

            std::cout << '\n';
        }
    }

    void BuildMap(vector<string>& allowed)
    {
        for (const auto& x : allowed)
        {
            string curr;
            curr += x[0];
            curr += x[1];

            res[curr].push_back(x[2]);
        }
    }

private:
    unordered_map<string, vector<char>> res;
    unordered_map<string, bool> memo;
};