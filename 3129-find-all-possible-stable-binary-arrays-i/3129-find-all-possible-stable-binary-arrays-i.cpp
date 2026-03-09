class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) 
    {
        //Was 4D dp, now 3D???
        memset(dp, -1, sizeof(dp));

        long long res = 0;

        res += dfs(zero, one, 0, limit);
        res += dfs(zero, one, 1, limit);

        return res % MOD;
    }

    int dfs(int zero, int one, int last, int& limit)
    {

        if (zero < 0 || one < 0)
        {
            return 0;
        }

        if (zero == 0 && one == 0)
        {
            return 1;
        }

        if (dp[zero][one][last] != -1)
        {
            return dp[zero][one][last];
        }

        long long res = 0;

        if (last == 0)
        {
            for (int k = 1; k <= limit; k++)
            {
                if (zero - k < 0) break;

                if (zero - k == 0 && one == 0)
                {
                    res += 1;
                }
                else
                {
                    res += dfs(zero - k, one, 1, limit);
                }

                res %= MOD;
            }
        }
        else
        {
            for (int k = 1; k <= limit; k++)
            {
                if (one - k < 0) break;

                if (zero == 0 && one - k == 0)
                {
                    res += 1;
                }
                else
                {
                    res += dfs(zero, one - k, 0, limit);
                }

                res %= MOD;
            }
        }

        return dp[zero][one][last] = res;
    }

private:
    static const int MOD = 1e9 + 7;
    int dp[201][201][2];
};