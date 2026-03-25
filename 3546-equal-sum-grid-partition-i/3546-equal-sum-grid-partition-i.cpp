class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        long long totalSum = 0;

        //Get total sum
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                totalSum += grid[i][j];
            }
        }

        long long topSum = 0;

        //Horizontal cuts
        for (int cut = 0; cut < rows - 1; cut++)
        {

            for (int j = 0; j < cols; j++)
            {
                topSum += grid[cut][j];
            }

            long long bottomSum = totalSum - topSum;

            if (topSum == bottomSum)
            {
                return true;
            }

        }

        long long leftSum = 0;
        
        //Vertical cuts
        for (int cut = 0; cut < cols - 1; cut++)
        {

            for (int i = 0; i < rows; i++)
            {
                leftSum += grid[i][cut];
            }

            long long rightSum = totalSum - leftSum;

            if (leftSum == rightSum)
            {
                return true;
            }
        }

        return false;
    }
};