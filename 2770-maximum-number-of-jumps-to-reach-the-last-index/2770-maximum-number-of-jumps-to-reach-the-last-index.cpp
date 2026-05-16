class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) 
    {
        int n = nums.size();
        vector<int> dp(n, -2);

        return dfs(0, nums, dp, target, n);
    }

    int dfs(int i, vector<int>& nums, vector<int>& dp, int target, int n)
    {

        if (i == n - 1)
        {
            //We made it
            return 0;
        }

        //Check if dp has something
        if (dp[i] != -2)
        {
            return dp[i];
        }

        int best = -1;

        for (int j = i + 1; j < nums.size(); j++)
        {
            if (abs(nums[j] - nums[i]) <= target)
            {
                int result = dfs(j, nums, dp, target, n);

                if (result != -1 )
                {
                    //Calc best
                    best = max(best, 1 + result);
                }

            }
        }

        //RETURN best...
        dp[i] = best;

        return best;
    }

private:

};