class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        //Create dp array and set first val of 2d matrix
        //Vec defaults 0
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        dp[0][0] = grid[0][0];

        //First row
        for (int i = 1; i < cols; i++)
        {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        //First Col
        for (int j = 1; j < rows; j++)
        {
            dp[j][0] = dp[j-1][0] + grid[j][0];
        }
        
        //Every other cell to right corner.
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                dp[i][j] = std::min(dp[i-1][j] + grid[i][j], dp[i][j-1] + grid[i][j]);
            }
        }

        return dp[rows - 1][cols - 1];
    }
};