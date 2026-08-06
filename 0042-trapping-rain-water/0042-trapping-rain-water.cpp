class Solution {
public:
    int trap(vector<int>& height) 
    {
        int right = height.size() - 1;
        int left = 0;
        int leftMax = 0;
        int rightMax = 0;
        int res = 0;

        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (height[left] >= leftMax)
                {
                    leftMax = height[left];
                }
                else
                {
                    res += leftMax - height[left];
                }

                left += 1;
            }
            else
            {
                if (height[right] >= rightMax)
                {
                    rightMax = height[right];
                }
                else
                {
                    res += rightMax - height[right];
                }
                
                right -= 1;
            }
        }

        return res;
    }
};