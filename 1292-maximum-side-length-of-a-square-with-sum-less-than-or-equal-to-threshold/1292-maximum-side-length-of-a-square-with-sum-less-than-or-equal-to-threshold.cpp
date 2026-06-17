class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) 
    {
        vector<vector<int>> res = BuildPrefixSum(mat);
        printPrefixSum(res);

        int rows = res.size();
        int cols = res[0].size();

        for (int size = 1; size <= min(rows, cols); size++)
        {
            bool found = false;

            for (int row = 0; row + size <= mat.size(); row++)
            {
                for (int col = 0; col + size <= mat[0].size(); col++)
                {
                    int sum = getSquareSum(res, row, col, size);

                    if (sum <= threshold)
                    {
                        ans = size;
                        found = true;
                    }
                }
            }
        }

        return ans;
    }

    int getSquareSum(vector<vector<int>>& prefix,
                 int row,
                 int col,
                 int size)
    {
        int r1 = row;
        int c1 = col;
        int r2 = row + size;
        int c2 = col + size;

        return prefix[r2][c2]
            - prefix[r1][c2]
            - prefix[r2][c1]
            + prefix[r1][c1];
    }

    vector<vector<int>> BuildPrefixSum(vector<vector<int>>& mat)
    { 
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> res(rows + 1, vector<int>(cols + 1, 0));

        for (int row = 1; row <= rows; row++)
        {
            for (int col = 1; col <= cols; col++)
            {
                res[row][col] = mat[row - 1][col - 1] + 
                res[row - 1][col] + 
                res[row][col - 1] - 
                res[row - 1][col - 1];
            }
        }

        return res;
    }

    void printPrefixSum(const vector<vector<int>>& prefix)
    {
        for (const auto& row : prefix)
        {
            for (int num : row)
            {
                cout << setw(4) << num;
            }
            cout << '\n';
        }
    }

private:
    int ans = 0;
};