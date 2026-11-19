class Solution {
public:
    int minimizeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int minNum = nums[0];
        int maxNum = nums[n - 1];
        int secondMinNum = nums[1];
        int secondMaxNum = nums[n - 2];
    
        int x = FindNewTotal(maxNum, minNum, nums);
        int y = FindNewTotal(secondMinNum, minNum, nums);
        int z = FindNewTotal(maxNum, secondMaxNum, nums);

        return std::min({x, y, z});
    }

    int FindNewTotal(int x, int y, vector<int>& nums)
    {
        vector<int> left = nums;
        left.erase(find(left.begin(), left.end(), x));
        left.erase(find(left.begin(), left.end(), y));

        // Still sorted, so front is the new min and back is the new max
        return left.back() - left.front();
    }

private:
    int res = 0;
};