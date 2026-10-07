class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) 
    {
        vector<int> res(2 * n, 0);

        for (int i{}; i < n; i++)
        {
            int x = nums[i];
            int y = nums[i + n];

            res[2 * i] = x;
            res[2 * i + 1] = y;
        }    

        return res;
    }
};