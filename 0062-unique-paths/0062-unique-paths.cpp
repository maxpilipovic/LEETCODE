using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int rows = m;
        int cols = n;
        //Top-down - using DP TABLE
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        dp[0][0] = 1;

        //First row
        for (int i = 1; i < cols; i++)
        {
            dp[0][i] = 1;
        }

        //First col
        for (int j = 1; j < rows; j++)
        {
            dp[j][0] = 1;
        }

        //We want to loop everything in middle!!!
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j-1];
            }
        }

        return dp[rows - 1][cols - 1];
    }
};