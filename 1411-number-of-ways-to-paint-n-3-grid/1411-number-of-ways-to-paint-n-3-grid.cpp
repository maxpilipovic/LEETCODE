class Solution {
public:
    int numOfWays(int n) 
    {
        
        const long long MOD = 1e9 + 7;
        std::vector<std::array<long long, 2>> dp(n + 1);

        //ABA
        dp[1][0] = 6;

        //ABC
        dp[1][1] = 6;

        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = (3 * dp[i - 1][0] + 2 * dp[i - 1][1]) % MOD;
            dp[i][1] = (2 * dp[i - 1][0] + 2 * dp[i - 1][1]) % MOD;
        }

        return (int)((dp[n][0] + dp[n][1]) % MOD);
    }

private:

};