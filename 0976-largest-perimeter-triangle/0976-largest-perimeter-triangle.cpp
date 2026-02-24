class Solution {
public:
    int largestPerimeter(vector<int>& nums) 
    {
        
        //Base Case
        if (nums.size() < 3)
        {
            return 0;
        }

        //Sort
        sort(nums.begin(), nums.end());

        int res = 0;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            int a = nums[i];
            int b = nums[i + 1];
            int c = nums[i + 2];

            if (a + b > c && a + c > b && b + c > a)
            {
                res = max(res, a + b + c);
            }
        }   

        return res; 
    }

private:

};