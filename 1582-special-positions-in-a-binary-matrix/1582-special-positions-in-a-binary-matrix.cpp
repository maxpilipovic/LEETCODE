class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) 
    {

        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat[i][j] == 1)
                {
                    if (check(i, j, rows, cols, mat))
                    {
                        res += 1;
                    }
                }
            }
        }

        return res;
    }

    bool check(int i, int j, int& rows, int& cols, vector<vector<int>>& mat)
    {
        //up
        for (int r = i - 1; r >= 0; r--)
        {
            if (mat[r][j] == 1) 
            {
                return false;
            }
        }

        // down
        for (int r = i + 1; r < rows; r++)
        {
            if (mat[r][j] == 1) 
            {
                return false;
            }
        }

        // left
        for (int c = j - 1; c >= 0; c--)
        {
            if (mat[i][c] == 1)
            {
                return false;
            }
        }

        // right
        for (int c = j + 1; c < cols; c++)
        {
            if (mat[i][c] == 1)
            {
                return false;
            }
        }

        return true;
    }

private:
    int res = 0;

};