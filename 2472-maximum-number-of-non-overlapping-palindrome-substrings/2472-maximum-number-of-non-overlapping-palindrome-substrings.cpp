class Solution {
public:
    int maxPalindromes(string s, int k) 
    {
        int n = s.size();

        //Size n + 1 filled with zeros.
        vector<int> dp(n + 1, 0);

        //the 
        auto isPal = [&](int l, int r)
        {
            while (l < r)
            {
                if (s[l] != s[r])
                {
                    return false;
                }

                l += 1;
                r -= 1;
            }

            return true;
        };

        for (int i = 1; i <= n; i++)
        {

            dp[i] = dp[i - 1];

            if (i - k >= 0 && isPal(i - k, i - 1))
            {
                //Max of current. 
                dp[i] = max(dp[i], dp[i - k] + 1);
            }

            if (i - (k + 1) >= 0 && isPal(i - (k + 1), i - 1)) 
            {
                dp[i] = max(dp[i], dp[i - (k + 1)] + 1);
            }
        }

        return dp[n];
    }
};