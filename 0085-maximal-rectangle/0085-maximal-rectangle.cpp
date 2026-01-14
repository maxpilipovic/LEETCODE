class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> matrix2(rows, vector<int>(cols, 0));

        //Does first row...
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix2[0][j] = (matrix[0][j] == '1') ? 1 : 0;
            }
        }

        //Fill the remainding rows
        for (int i = 1; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == '1') matrix2[i][j] = matrix2[i - 1][j] + 1;
                else matrix2[i][j] = 0;
            }
        }

        printMatrix(matrix2);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix2[i][j] == 0) continue;

                int minHeight = matrix2[i][j];

                // walk LEFT to build width, shrinking height by min
                for (int k = j; k >= 0 && matrix2[i][k] > 0; k--)
                {
                    minHeight = min(minHeight, matrix2[i][k]);
                    int width = j - k + 1;
                    res = max(res, minHeight * width);
                }
            }
        }

        return res;
    }

    void printMatrix(const vector<vector<int>>& matrix) 
    {
        for (int i = 0; i < (int)matrix.size(); i++) 
        {
            for (int j = 0; j < (int)matrix[i].size(); j++) 
            {
                cout << matrix[i][j] << ' ';
            }
            cout << '\n';
        }
    }

private:
    int res = 0;

};