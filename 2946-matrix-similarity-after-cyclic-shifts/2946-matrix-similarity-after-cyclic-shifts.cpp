class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) 
    {
        int rows = mat.size();
        int cols = mat[0].size();

        //Instead of doing more shifts (you wrap around what you got) //Optimization.
        k %= cols;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int shiftedValue;

                if (i % 2 == 0)
                {
                    //Even
                    shiftedValue = mat[i][(j + k) % cols];
                }
                else
                {
                    //Odd
                    shiftedValue = mat[i][(j - k + cols) % cols];
                }

                if (shiftedValue != mat[i][j])
                {
                    return false;
                }
            }
        }

        return true;
    }
};