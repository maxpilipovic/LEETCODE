class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {

        //Fills vector with zeros.
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int rows = matrix.size();
        int cols = matrix[0].size();
        int length = matrix.size();

        //Loop over
        for (const auto& q : queries)
        {
            int r1 = q[0];
            int c1 = q[1];
            int r2 = q[2];
            int c2 = q[3];

            //Increment our first location
            matrix[r1][c1] += 1;

            //First row after the rectangle
            if (r2 + 1 < n)
            {
                matrix[r2 + 1][c1] += -1;
            }

            //First colum after the rectangle
            if (c2 + 1 < n)
            {
                matrix[r1][c2 + 1] += -1;
            }

            if (r2 + 1 < n && c2 + 1 < n)
            {
                matrix[r2 + 1][c2 + 1] += 1;
            }

        }

        //Horizontally - Start one ahead
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                matrix[i][j] = matrix[i][j - 1] + matrix[i][j];
            }
        }

        //Vertically
        for (int j = 0; j < n; j++)
        {
            for (int i = 1; i < n; i++)
            {
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j];
            }
        }

        return matrix;
    }
};