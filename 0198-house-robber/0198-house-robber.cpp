class Solution {
public:
    int rob(vector<int>& nums) {
        
        int startZero = dfs(0, nums);
        int startOne = dfs(1, nums);

        maxRes = std::max(startZero, startOne);

        return maxRes;
    }
    
    int dfs(int i, vector<int>& nums)
    {
        int curr = 0;
        //Base Case //BOUNDS
        if (i >= nums.size())
        {
            return 0;
        }

        if (dp.count(i))
        {
            return dp[i];
        }

        //Rob the house
        curr += nums[i];
        
        int take = curr + dfs(i + 2, nums);
        int skip = dfs(i + 1, nums);

        dp[i] = std::max(take, skip);

        return dp[i];
    }

private:
    int maxRes = INT_MIN;
    unordered_map<int, int> dp;
};