class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {   
        int n = nums.size();
        vector<int> dp(n);

        //Start with 0 as the first num
        dp[0] = nums[0];
        res = dp[0];

        //Call recursive function
        dfs(1, dp[0], dp, nums, n);

        return res;
    }

    void dfs(int i, int count, vector<int>& dp, vector<int>& nums, int n)
    {
        //Base Case... Out of bounds
        if (i >= n)
        {
            return;
        }

        if (dp[i - 1] < 0)
        {
            //Restart
            count = nums[i];
        }
        else
        {
            //Extend
            count += nums[i];
        }

        //Take the max.
        res = max(res, count);

        //Attach it to dp.
        dp[i] = count;

        //Recursive
        dfs(i + 1, count, dp, nums, n);
    }

private:
    int res = INT_MIN;
};