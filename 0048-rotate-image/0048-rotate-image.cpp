class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();

        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i{}; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                //Swap last with first.
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (auto& row : matrix)
        {
            reverse(row.begin(), row.end());
        }

    }
};