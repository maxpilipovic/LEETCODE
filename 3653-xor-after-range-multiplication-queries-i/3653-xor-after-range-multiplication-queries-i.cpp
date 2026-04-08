class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
    {
        const int MOD = 1e9 + 7;

        for (int i = 0; i < queries.size(); i++)
        {
            int li = queries[i][0];
            int ri = queries[i][1];
            int ki = queries[i][2];
            int vi = queries[i][3];

            int temp = li;

            while (temp <= ri)
            {
                nums[temp] = (1LL * nums[temp] * vi) % MOD;
                temp += ki;
            }

        }

        //Bitwise xor everything
        int x = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            x ^= nums[i];
        }

        return x;
    }

private:
    int res = 0;
};