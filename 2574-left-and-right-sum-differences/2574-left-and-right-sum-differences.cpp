class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) 
    {
        vector<int> leftPrefix(nums.size());
        leftPrefix[0] = 0;
        for (size_t i = 1; i < nums.size(); i++)
        {
            leftPrefix[i] = leftPrefix[i - 1] + nums[i - 1];
        }

        vector<int> rightPrefix(nums.size());
        rightPrefix[nums.size() - 1] = 0;

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            rightPrefix[i] = rightPrefix[i + 1] + nums[i + 1];
        }

        vector<int> res(nums.size());

        for (size_t i{}; i < nums.size(); i++)
        {
            res[i] = abs(leftPrefix[i] - rightPrefix[i]);
        }

        return res;
    }

private:
    int x = 0;
};