class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int total = rows * cols;
        k = k % total;

        //Same size as grid but with 0's
        vector<vector<int>> res(rows, vector<int>(cols, 0));

        for (int row{}; row < rows; row++)
        {
            for (int col{}; col < cols; col++)
            {
                //Flatten
                int idx = row * cols + col;


                int newIdx = (idx + k) % total;

                int newRow = newIdx / cols;
                int newCol = newIdx % cols;

                res[newRow][newCol] = grid[row][col];

            }
        }

        return res;
    }

private:

};