#include <cmath>
#include <cstdlib>

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        
        //res being max
        int res = 0;
        double maxDiagonal = -0;

        for (const auto &rect : dimensions)
        {
            //Double?
            int length = rect[0];
            int width = rect[1];

            double diagonal = sqrt((double)length * length + (double)width * width);
            int area = length * width;

            if (diagonal > maxDiagonal)
            {
                maxDiagonal = diagonal;
                res = area;
            }
            //Correct //precision ==.
            else if (abs(diagonal - maxDiagonal) < 1e-9)
            {
                res = max(res, area);
            }
        }

        return res;
    }
};