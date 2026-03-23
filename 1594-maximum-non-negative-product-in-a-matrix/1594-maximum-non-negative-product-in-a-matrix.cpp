class Solution 
{
    static constexpr long long INF = 4e18;
    static constexpr int MOD = 1e9 + 7;
public:
    int maxProductPath(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<pair<long long, long long>>> dp(
            rows, vector<pair<long long, long long>>(cols)
        );

        vector<vector<bool>> visited(
            rows, vector<bool>(cols, false)
        );

        pair<long long, long long> ans = dfs(0, 0, grid, dp, rows, cols, visited);
        long long best = ans.first;

        if (best < 0)
        {
            return -1;
        }

        return best % MOD;
    }

    pair<long long, long long> dfs(int row, int col, vector<vector<int>>& grid, vector<vector<pair<long long, long long>>>& dp, int& rows, int& cols, vector<vector<bool>>& visited)
    {
        //If out of bounds
        if (row < 0 || row >= rows || col < 0 || col >= cols)
        {
            //RETURN INF
            return {-INF, INF};
        }

        //If at destination
        if (row == rows - 1 && col == cols - 1)
        {
            return {grid[row][col], grid[row][col]};
        }

        //Check if it exisits already in DP
        if (visited[row][col])
        {
            return dp[row][col];
        }

        //CHOOSE! Move right or down
        pair<long, long> right = dfs(row, col + 1, grid, dp, rows, cols, visited);
        pair<long, long> down = dfs(row + 1, col, grid, dp, rows, cols, visited);

        long long val = grid[row][col];

        long long maxProd = -INF;
        long long minProd = INF;

        //Try right child if valid
        if (right.first != -INF)
        {
            long long a = val * right.first;
            long long b = val * right.second;

            maxProd = max(maxProd, max(a, b));
            minProd = min(minProd, min(a, b));
        }

        //Try down child if valid
        if (down.first != -INF)
        {
            long long a = val * down.first;
            long long b = val * down.second;

            maxProd = max(maxProd, max(a, b));
            minProd = min(minProd, min(a, b));
        }

        //STORE in DP
        dp[row][col] = {maxProd, minProd};

        //ADDED TO VISITED
        visited[row][col] = true;

        return dp[row][col];
    }
};