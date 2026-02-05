class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) 
    {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;

        int share = 0;

        //Start at day 2.
        for (int i = 2; i < n + 1; i++)
        {
            if (i - delay > 0)
            {
                //Add people
                share = (share + dp[i - delay]) % MOD;
            }

            if (i - forget > 0)
            {
                share = (share - dp[i - forget] + MOD) % MOD;
            }

            dp[i] = share;
        }

        for (int i = n - forget + 1; i < n + 1; i++)
        {
            res = (res + dp[i]) % MOD;
        }

        return res;
        
    }

private:
    int res = 0;
    const int MOD = 1000000007;
};