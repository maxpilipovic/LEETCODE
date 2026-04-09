class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        vector<vector<vector<int>>> dp(
            strs.size(),
            vector<vector<int>>(m + 1, vector<int>(n + 1, -1))
        );

        return dfs(0, n, m, strs, dp);
    }

    int dfs(int i, int onesLeft, int zerosLeft, vector<string>& strs, vector<vector<vector<int>>>& dp)
    {

        if (i == strs.size())
        {
            //get max
            return 0;
        }

        //Memo
        if (dp[i][zerosLeft][onesLeft] != -1)
        {
            return dp[i][zerosLeft][onesLeft];
        }

        pair<int, int> take = findValues(strs[i]);
        int ones = take.first;
        int zeros = take.second;

        //Skip
        int skip = dfs(i + 1, onesLeft, zerosLeft, strs, dp);

        int pick = 0;
        if (zerosLeft >= zeros && onesLeft >= ones)
        {
            pick = 1 + dfs(i + 1, onesLeft - ones, zerosLeft - zeros, strs, dp);
        }

        return dp[i][zerosLeft][onesLeft] = max(pick, skip);
    }

    std::pair<int, int> findValues(string curr)
    {
        
        std::pair<int, int> x(0, 0); //{ones, zeros}

        for (int i = 0; i < curr.size(); i++)
        {
            if (curr[i] == '1')
            {
                x.first += 1;
            }
            else
            {
                x.second += 1;
            }
        }

        return x;
    }

};