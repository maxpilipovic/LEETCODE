class Solution 
{
public:
    int countSubmatrices(vector<vector<int>>& grid, int k)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<long long>> prefix(rows, vector<long long>(cols, 0));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                prefix[i][j] = grid[i][j];

                if (i > 0)
                {
                    prefix[i][j] = prefix[i][j] += prefix[i - 1][j];
                }

                if (j > 0)
                {
                    prefix[i][j] = prefix[i][j] += prefix[i][j - 1];
                }

                if (i > 0 && j > 0)
                {
                    prefix[i][j] -= prefix[i - 1][j - 1];
                }

                if (prefix[i][j] <= k)
                {
                    res += 1;
                }
            }
        }

        return res;
    }
private:
    int res = 0;
};