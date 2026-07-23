class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        //Transpose ... Mirror on the diagonal.
        for (int i{}; i < rows; i++)
        {
            for (int j = i + 1; j < cols; j++)
            {

                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //Reverse each row
        for (auto& row : matrix)
        {
            reverse(row.begin(), row.end());
        }
    }
};