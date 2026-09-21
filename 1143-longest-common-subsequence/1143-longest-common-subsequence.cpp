class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        
        std::map<pair<int, int>, int> map;
        return dfs(0, 0, text1, text2, map);
    }

    int dfs(int i, int j, std::string& text1, std::string& text2, std::map<pair<int, int>, int>& map)
    {

        //Base Case
        if (i >= text1.size() || j >= text2.size())
        {
            return 0;
        }

        if (map.count({i, j}))
        {
            return map[{i, j}];
        }

        int result = 0;

        //Case 1. Increase both
        if (text1[i] == text2[j])
        {
            result = 1 + dfs(i + 1, j + 1, text1, text2, map);
        }
        else
        {

            //Case 2 incresae either!
            result = std::max(dfs(i + 1, j, text1, text2, map), dfs(i, j + 1, text1, text2, map));
        }

        //Add to dp
        map[{i, j}] = result;

        return result;
    }

private:

};