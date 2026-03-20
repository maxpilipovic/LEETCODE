class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> x(rows + 1, vector<int>(cols + 1, 0));
        vector<vector<int>> y(rows + 1, vector<int>(cols + 1, 0));

        for (int i = 1; i <= rows; i++)
        {
            for (int j = 1; j <= cols; j++)
            {
                x[i][j] = x[i - 1][j] + x[i][j - 1] - x[i - 1][j - 1];
                y[i][j] = y[i - 1][j] + y[i][j - 1] - y[i - 1][j - 1];

                if (grid[i - 1][j - 1] == 'X')
                {
                    x[i][j] += 1;
                }

                if (grid[i - 1][j - 1] == 'Y')
                {
                    y[i][j] += 1;
                }

                if (x[i][j] > 0 && x[i][j] == y[i][j])
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