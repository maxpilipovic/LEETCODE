class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        //3D DP ARRAY
        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n, vector<int>(k, -1))
        );

        return dfs(0, 0, 0, grid, k, m, n, dp);   
    }

    int dfs(int i, int j, int currSum, vector<vector<int>>& grid, int& k, int& m, int& n, vector<vector<vector<int>>>& dp)
    {
        //Rows -> m Cols -> n
        //Base Cases
        if (i < 0 || j < 0 || i >= m || j >= n)
        {
            return 0;
        }

        //WHAT I WOULD DO
        //Safely increment...
        //currSum += grid[i][j];
        //Do modulo
        //int modulo = currSum % k;

        currSum = (currSum + grid[i][j]) % k; 

        //Check our cache
        if (dp[i][j][currSum] != -1)
        {
            return dp[i][j][currSum];
        }

        //Check if we are at m - 1, n - 1;
        if (i == m - 1 && j == n - 1)
        {
            //Check if divisible
            if (currSum % k == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        //Go right
        int right = dfs(i, j + 1, currSum, grid, k, m, n, dp);

        //Go down
        int down = dfs(i + 1, j, currSum, grid, k, m, n, dp);

        dp[i][j][currSum] = (right + down) % MOD;

        return dp[i][j][currSum];
    }   

private:

    map<std::tuple<int, int, int>, int> dp;
    const int MOD = 1000000007;
    //vector<pair<int, int>> directions = {{1, 0}, {0, 1}} //Down, right
};