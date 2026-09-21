class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<vector<long long>> memo(n, vector<long long>(k, -1));
        vector<long long> res(k, 0);

        //Start at back and loop through each remainder
        for (int i = n - 1; i >= 0; i--)
        {
            for (int r = 0; r < k; r++)
            {
                res[r] += dfs(i, r, k, nums, memo);
            }
        }

        return res;
    }

    long long dfs(int i, int r, int k, vector<int>& nums, vector<vector<long long>>& memo)
    {
        if (i >= (int)nums.size())
        {
            return 0;
        }

        if (memo[i][r] != -1)
        {
            return memo[i][r];
        }

        long long count = 0;
        int cur = nums[i] % k;

        //
        if (cur == r)
        {
            count++;
        }

        for (int prev = 0; prev < k; prev++)
        {
            if ((cur * prev) % k == r)
            {
                count += dfs(i + 1, prev, k, nums, memo);
            }
        }

        memo[i][r] = count;
        return count;
    }

private:

};