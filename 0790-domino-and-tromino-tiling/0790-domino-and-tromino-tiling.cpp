class Solution {
public:
    int numTilings(int n) 
    {
        vector<vector<int>> dp(n + 1, vector<int>(4, -1));

        return (int)dfs(0, 0, n, dp);
    }

    long long dfs(int i, int mask, int n, vector<vector<int>>& dp)
    {
        //Got to the end
        if (i == n)
        {
            return (mask == 0);
        }

        int &memo = dp[i][mask];
        if (memo != -1)
        {
            return memo;
        }

        long long res = 0;

        if (mask == 0)
        {
            //Vertical domino in this column
            res += dfs(i + 1, 0, n, dp);

            if (i + 1 < n)
            {
                //Two horizontal dominos (top & bottom)
                res += dfs(i + 1, 3, n, dp);

                //Trominos that use botrh cells of this column + one of next
                res += dfs(i + 1, 1, n, dp);
                res += dfs(i + 1, 2, n, dp);
            }
        }

        else if (mask == 1)
        {
            if (i + 1 < n)
            {
                //Horizontal domino (bottom of next becomes filled)
                res += dfs(i + 1, 2, n, dp);

                //Tromino
                res += dfs(i + 1, 3, n, dp);
            }
        }
        else if (mask == 2)
        {
            if (i + 1 < n)
            {
                //Horizontal domino
                res += dfs(i + 1, 1, n, dp);

                //Tromino
                res += dfs(i + 1, 3, n, dp);
            }
        }
        else
        {
            //mask = 3
            res += dfs(i + 1, 0, n, dp);
        }

        memo = (int)(res % MOD);
        return memo;
    }

private:
    const int MOD = 1e9 + 7;
};