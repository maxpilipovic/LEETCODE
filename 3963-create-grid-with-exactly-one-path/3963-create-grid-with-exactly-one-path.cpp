class Solution {
public:
    vector<string> createGrid(int m, int n) 
    {
        //Fill with #'s
        int rows = m;
        int cols = n;
        vector<string> res(m, string(n, '#'));

        vector<pair<int, int>> directions = 
        {
            {0, 1},
            {1, 0}    
        };

        dfs(0, 0, rows, cols, res, directions);

        return res;
    }

    void dfs(int row, int col, int rows, int cols, vector<string>& res, vector<pair<int, int>>& directions)
    {

        res[row][col] = '.';

        //Base Case
        if (row == rows - 1 && col == cols - 1)
        {
            return;
        }

        //Check bounds
        for (auto [nr, nc] : directions)
        {
            int newRow = nr + row;
            int newCol = nc + col;

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols)
            {
                dfs(newRow, newCol, rows, cols, res, directions);
                return;
            }
        }

        return;
    }

private:

};