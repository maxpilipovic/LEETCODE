class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) 
    {
        //Dp problem
        int rows = coins.size();
        int cols = coins[0].size();

        //Create dp vector //3D
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(3, INT_MIN)));


        //Start dp
        return dfs(0, 0, 2, coins, dp, rows, cols);
    }

    int dfs(int i, int j, int k, vector<vector<int>>& coins, vector<vector<vector<int>>>& dp, int& rows, int& cols)
    {
        //Check bounds
        if (i < 0 || i >= rows || j < 0 || j >= cols)
        {
            return -1000000000;
        }

        //Base Case
        if (i == rows - 1 && j == cols - 1)
        {
            //If cell is negative, we can choose to neutralize it
            if (coins[i][j] < 0 && k > 0)
            {
                //Want either 0 or the other.
                return max(0, coins[i][j]);
            }

            return coins[i][j];
        }
        
        //Check dp
        if (dp[i][j][k] != INT_MIN)
        {
            return dp[i][j][k];
        }

        //Pick right or down //DO NOT NEUTRALIZE
        int right = dfs(i, j + 1, k, coins, dp, rows, cols);
        int down = dfs(i + 1, j, k, coins, dp, rows, cols);

        int best = coins[i][j] + max(right, down);

        //Pick right or down //NEUTRALIZE if negative
        if (coins[i][j] < 0 && k > 0)
        {
            int rightNeutral = dfs(i, j + 1, k - 1, coins, dp, rows, cols);
            int downNeutral = dfs(i + 1, j, k - 1, coins, dp, rows, cols);

            best = max(best, max(rightNeutral, downNeutral));
        }

        dp[i][j][k] = best;

        return best;
    }

private:
    int res = 0;
};