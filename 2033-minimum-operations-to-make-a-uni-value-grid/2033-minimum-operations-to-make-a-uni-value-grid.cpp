class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) 
    {
        //Flatten to 1d array
        for (auto& row : grid)
        {
            for (int val : row)
            {
                nums.push_back(val);
            }
        }

        //Sort
        sort(nums.begin(), nums.end());

        //Go through and see if possible
        int rem = nums[0] % x;
        for (int i{}; i < nums.size(); i++)
        {
            
            if (nums[i] % x != rem)
            {
                return -1;
            }

        }

        //Calculate with median
        int median = nums[nums.size() / 2];
        int operations = 0;

        for (int val : nums)
        {
            operations += abs(val - median) / x;
        }

        return operations;
    }

private:
    vector<int> nums;
    int res = 0;
};