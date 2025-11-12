class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<vector<int>>> dp(
            strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1))
        );
    
        //Do the recursion
        return recursion(strs, 0, m, n, dp);    
    }

    int recursion(vector<string>& strs, int index, int numZerosLeft, int numOnesLeft, vector<vector<vector<int>>>& dp)
    {

        if (index >= strs.size())
        {
            return 0;
        }

        if (dp[index][numZerosLeft][numOnesLeft] != -1)
        {
            return dp[index][numZerosLeft][numOnesLeft];
        }

        //Count zeros and 1's in string
        int ones = 0;
        int zeros = 0;

        for (char c : strs[index])
        {
            if (c == '0')
            {
                zeros += 1;
            }
            if (c == '1')
            {
                ones += 1;
            }
        }

        //Take or skip?
        int skip = recursion(strs, index + 1, numZerosLeft, numOnesLeft, dp);

        int take = 0;
        if (numZerosLeft >= zeros && numOnesLeft >= ones)
        {
            take = 1 + recursion(strs, index + 1, numZerosLeft - zeros, numOnesLeft - ones, dp);
        }

        return dp[index][numZerosLeft][numOnesLeft] = max(take, skip);
    }

private:
};