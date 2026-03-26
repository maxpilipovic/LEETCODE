class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) 
    {
        
        if (grid.empty() || grid[0].empty()) return {};
        
        //Flatten 1D
        int rows = grid.size();
        int cols = grid[0].size();
        const int MOD = 12345;     
        vector<int> nums;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                nums.push_back(grid[i][j]);
            }
        }

        int size = nums.size();

        //Create the prefix vector
        vector<int> prefix(size);
        prefix[0] = 1;

        for (int i = 1; i < prefix.size(); i++)
        {
            prefix[i] = (1LL * prefix[i - 1] * nums[i - 1]) % 12345;
        }

        //Create the suffix vector
        vector<int> suffix(size);
        suffix[size - 1] = 1;

        for (int j = size - 2; j >= 0; j--)
        {
            suffix[j] = (1LL * suffix[j + 1] * nums[j + 1]) % MOD;
        }

        //Res vector
        vector<int> res(size);
        
        for (int i = 0; i < res.size(); i++)
        {
            res[i] = (1LL * prefix[i] * suffix[i]) % 12345;
        }

        vector<vector<int>> ans(rows, vector<int>(cols));
        int idx = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                ans[i][j] = res[idx++];
            }
        }

        return ans;
    }
private:

};