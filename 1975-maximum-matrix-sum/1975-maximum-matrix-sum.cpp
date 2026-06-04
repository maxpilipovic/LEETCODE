class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        long long maxNum = 0;
        int posNum = 0;
        int negNum = 0;
        int minNum = INT_MAX;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int num = matrix[i][j];
                
                //Find minNum
                minNum = min(minNum, abs(num));

                //Add to maxNum
                maxNum += abs(num);

                if (num < 0)
                {
                    negNum += 1;
                }        
                else
                {
                    posNum += 1;
                }
            }
        }

        if (negNum % 2 == 0)
        {
            return maxNum;
        }

        return (maxNum - 2LL * minNum);
    }
};