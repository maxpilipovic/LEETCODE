class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) 
    {
        int rows = boxGrid.size();
        int cols = boxGrid[0].size();

        for (int i{}; i < rows; i++)
        {
            int empty = cols - 1;

            for (int j = cols - 1; j >= 0; j--)
            {
                if (boxGrid[i][j] == '*')
                {
                    //Make it in front of it.
                    empty = j - 1;
                }
                else if (boxGrid[i][j] == '#')
                {
                    //If its a stone
                    swap(boxGrid[i][j], boxGrid[i][empty]);

                    //Move front one more.
                    empty--;
                }
            }
        }

        //Create new Vec
        vector<vector<char>> boxGrid2(cols, vector<char>(rows));

        //Flip it 90 degrees.
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                boxGrid2[col][rows - 1 - row] = boxGrid[row][col];
            }
        }

        return boxGrid2;
    }

private:
    int res = 0;
};