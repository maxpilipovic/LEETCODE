class Solution {
public:

    void printMatrix(vector<vector<int>>& mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cout << mat[i][j] << " ";
            }
        }
    }
    int countSquares(vector<vector<int>>& matrix) {
        

        int rows = matrix.size();
        int cols = matrix[0].size();
        int res = 0;

        //dp memo. //array.
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        //dp[1][2] = 5;
        printMatrix(dp);

        for (int row = 0; row < rows; row++) 
        {
            for (int col = 0; col < cols; col++)
            {
                if (matrix[row][col] == 1)
                {
                    if (row == 0 || col == 0) //Checking (sides)
                    {

                        dp[row][col] = 1;
                    }
                    else
                    {
                        dp[row][col] = 1 + min({dp[row-1][col-1], dp[row-1][col], dp[row][col-1]});
                    }
                    res += dp[row][col];
                }
            }
        }
        return res;
    }

private:


};