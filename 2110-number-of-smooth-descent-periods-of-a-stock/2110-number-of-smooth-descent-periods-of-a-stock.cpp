class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) 
    {
        //DP VERSION
        for (int i = 0; i < prices.size(); i++)
        {
            if (i > 0 && prices[i] == prices[i - 1] - 1)
            {
                dp[i] = dp[i - 1] + 1;
            }
            else 
            {
                dp[i] = 1;
            }

            res += dp[i];
        }

        return res;
    }

private:
    unordered_map<int, long long> dp;
    long long res = 0;
};