class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        int res = 0;
        
        int top = rows;
        int bottom = -1;
        int right = -1;
        int left = cols;



        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {

                if (grid[row][col] == 1)
                {
                    //top
                    if (row < top) {top = row;}
                    //bottom
                    if (row > bottom) {bottom = row;}
                    //left
                    if (col > right) {right = col;}
                    //right
                    if (col < left) {left = col;}
                }
            }
        }

        std::cout << top << std::endl;
        std::cout << bottom << std::endl;
        std::cout << right << std::endl;
        std::cout << left << std::endl;
        return (bottom - top + 1) * (right - left + 1);
    }
};