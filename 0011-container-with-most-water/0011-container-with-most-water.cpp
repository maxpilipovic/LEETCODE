class Solution {
public:
    int maxArea(vector<int>& height) {
        
        
        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {
            int width = right - left;
            int height2 = std::min(height[left], height[right]);
            int area = findArea(width, height2, height);
            //Take max.. before move.
            resMax = std::max(resMax, area);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return resMax;

    }

    int findArea(int width, int height2, vector<int>& height)
    {
        int area = width * height2;

        return area;
    }

private:
    int resMax = 0;
};