class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int last = nums[n - 1];
        int sLast = nums[n - 2];

        return (last - 1) * (sLast - 1);
    }
};