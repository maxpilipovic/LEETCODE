class Solution {
public:
    int stoneGameII(vector<int>& piles) 
    {
        int n = piles.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        vector<int> suffix(n + 1, 0);;

        for (int i = n - 1; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        return startSimulation(0, 1, n, dp, suffix);
    }

    int startSimulation(int i, int m, int n, vector<vector<int>>& dp, vector<int>& suffix)
    {
        //Base Case... Out of bounds
        if (i >= n)
        {
            return 0;
        }

        //Check dp
        if (dp[i][m] != -1)
        {
            return dp[i][m];
        }

        //Recursive case
        int best = 0;
        
        for (int x = 1; x <= 2 * m && i + x <= n; x++)
        {
            int opponent = startSimulation(i + x, max(m, x), n, dp, suffix);
            int mine = suffix[i] - opponent;
            best = max(best, mine);
        }

        dp[i][m] = best;

        return dp[i][m];
    }

private:
    int res = 0;
};