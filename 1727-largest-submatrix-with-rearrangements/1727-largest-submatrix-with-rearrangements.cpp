class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();

        //Caculate columns
        for (int i = 1; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 1)
                {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }

        //Simulate rearranging
        for (int i = 0; i < rows; i++) 
        {
            vector<int> heights = matrix[i];
            sort(heights.rbegin(), heights.rend());

            for (int j = 0; j < cols; j++)
            {
                int height = heights[j];
                int width = j + 1;
                res = max(res, height * width);
            }
        }

        return res;
    }

private:
    int res = 0;
};