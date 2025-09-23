#include <unordered_map>
#include <map>  
#include <iostream>  

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        map<pair<int, int>, int> map;
        return dp(map, text1, text2, 0, 0);

    }

    int dp(map<pair<int, int>, int>& map, string& text1, string& text2, int i, int j)
    {

        //Bounds
        if (i >= text1.size() || j >= text2.size())
        {
            //Do something
            return 0; //not sure
        }

        //Check if its in dp...
        //Cache
        if (map.count({i, j}))
        {
            return map[{i, j}];
        }

        int result = 0;

        if (text1[i] == text2[j])
        {
            result = 1 + dp(map, text1, text2, i + 1, j + 1);
        }
        else 
        {
            result = std::max(dp(map, text1, text2, i + 1, j), dp(map, text1, text2, i, j + 1));
        }
        cout << result << endl;
        map[{i, j}] = result;

        return result;

    }
};