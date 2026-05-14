class Solution {
public:
    bool isGood(vector<int>& nums) 
    {
        int n = nums.size();

        //Sort
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++)
        {
            
            if (nums[i] != i + 1)
            {
                return false;
            }
        }

        return nums[n - 1] == n - 1;
    }

private:

};