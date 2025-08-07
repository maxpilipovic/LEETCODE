class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0;
        int right = (rows * cols) - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int midVal = matrix[mid / cols][mid % cols];

            if (target == midVal)
            {
                return true;
            }

            else if (midVal < target)
            {
                left = mid + 1;
            }

            else {
                right = mid - 1;
            }

        }

        return false;

    }
};