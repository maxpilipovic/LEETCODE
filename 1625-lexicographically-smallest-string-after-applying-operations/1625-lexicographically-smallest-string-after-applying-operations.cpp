class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {

        //Conver to int to compare...
        std::string res = s;

        dfs(s, a, b, res);

        return res;
    }

    void dfs(string s, int& a, int& b, std::string& res)
    {
        //Base Case
        if (visited.count(s))
        {
            //We found a duplicate, end...
            return;
        }

        //Add to visited...
        visited.insert(s);

        //Calculate the min
        res = std::min(res, s);

        //Apply Operation A
        string sA = applyOperationA(s, a);
        dfs(sA, a, b, res);

        //Apply Operation B
        string sB = applyOperationB(s, b);
        dfs(sB, a, b, res);

    }

    std::string applyOperationA(string s, int a)
    {

        std::string curr = s;

        for (int i = 0; i < s.size(); i++)
        {
            if (i % 2 != 0)
            {
                //Odd
                curr[i] = ((curr[i] - '0' + a) % 10) + '0';
            }
        }

        return curr;
    }

    std::string applyOperationB(string s, int b)
    {
        std::string curr = s;
        curr = curr.substr(curr.size() - b) + curr.substr(0, curr.size() - b);

        return curr;
    }

private:
    std::unordered_set<std::string> visited;
};