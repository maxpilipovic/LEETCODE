class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> nums2(2 * n, 0);

        for (int i{}; i < 2 * n; i++)
        {
            //How to wrap? Is this correct?
            int x = i % n;

            nums2[i] = nums[x];
        }

        return nums2;
    }
};