class Solution {
public:
    int jump(vector<int>& nums) 
    {
        vector<int> dp(nums.size(), -1);
        int n = nums.size();

        return dfs(nums, dp, 0, n);
    }

    int dfs(vector<int>& nums, vector<int>& dp, int i, int n)
    {
        //BASE CSE
        //Maybe remove this???
        if (i == n - 1)
        {
            return 0;
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }

        int minJumps = INT_MAX;

        for (int next = i + 1; next <= i + nums[i] && next < n; next++)
        {
            int jumpsFromNext = dfs(nums, dp, next, n);

            if (jumpsFromNext != INT_MAX)
            {
                minJumps = min(minJumps, 1 + jumpsFromNext);
            }
        }

        dp[i] = minJumps;

        return dp[i];
    }

private:

};